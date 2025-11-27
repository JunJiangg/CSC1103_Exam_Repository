#include <stdio.h>
#include <string.h>
#include <math.h>
#define max_size 3


typedef struct Point3D{ //Total 12 bytes
    float x; //4bytes
    float y;//4bytes
    float z;//4bytes
} Coordinate3D;


//Using both original struct name and typedef name is ok in the union structure.
//Union is NOT a struct is just a word or ways to group the 2 struct such that it tells the stack memory
//Share the same memory, create the stack memory base on the bigger struct so both can be allocated and used whenever
//Issue with this is, there might be a clash of resource in stack memory if both are used together
//union struct to group both 2D and 3D. union will use the bigger size struct to initialize in the stack memory
//So only 1 stack memory is initialized while whenever which is called. it will be able to fit
struct Euc_dist2D{
    struct Point3D GPSCood[max_size];
    float distance2D[max_size-1];
    float total_distance;
};

struct Euc_dist3D{
    struct Point3D GPSCood[max_size];
    float distance3D[max_size-1];
    float total_distance;
};
//remember to have ; at the end of struct

//a union of Euc_dist used to call either 2D or 3D struct depends on choice
//Remember this GPS question is asking to calculate distance from 1 point to 1 point to 1 point.
//if u have distance A -> B -> C
//it is used to calculate A->B + B->C distance
//where distance between 2 point A->B is sqrt(y2-y1) + sqrt(x2-x1);
//Then B->C is another sqrt(y2-y1) + sqrt(x2-x1); distance
union Euc_dist{
    struct Euc_dist2D dist_travel2D;
    struct Euc_dist3D dist_travel3D;
};
//Now the ptr holds the struct of dist_travel, so technicall u only need that ptr only to do stuff
//u wont need that original struct anymore. now access everything via pointer
void read_points(union Euc_dist *ptr_hold_dist_travel, int choice);
void dist_cal(union Euc_dist *ptr_hold_dist_travel, int choice);
void print_dist(union Euc_dist *ptr_hold_dist_travel, int choice);

int main(void){
    union Euc_dist dist_travel;
    union Euc_dist *ptr_hold_dist_travel;
    int choice;
    //now the ptr sees the entire dist_travel struct
    //so now u can do ptr_hold_dist_travel->dist_travel2D.GPSCood 
    //or ptr_hold_dist_travel->dist_travel3D.GPScood
    ptr_hold_dist_travel = &dist_travel;
    printf("\nPls enter the choice 1)2D Distance calculation");
    printf("\n                     2)3D Distance calculation");
    printf("\nChoice");
    scanf("%d", &choice);

    read_points(ptr_hold_dist_travel, choice);
    dist_cal(ptr_hold_dist_travel,choice);
    print_dist(ptr_hold_dist_travel,choice);


}

void read_points(union Euc_dist *ptr_hold_dist_travel, int choice){
    //choice here is enter 1 or 2 by user
    //1 is 2D, so Case 1 set for 2D
    //2 is 3D, Case 2 set for 3D
    switch (choice){
        case 1: 
        {
            //If user select 1 for Choice = 2D, loop 3 times to get 3 points of xyz,xyz,xyz coordinates
            //the value that we are scanning into in the GPSCood is a struct of 3D_Points, and inside x y z is a float.
            //So we scan %f.
            for(int i=0; i<max_size;++i){
                printf("\n Please enter Coordinate GPS for %d for x", i);
                scanf("%f", &(ptr_hold_dist_travel->dist_travel2D.GPSCood[i].x));
                printf("\n Please enter Coordinate GPS for %d for y", i);
                scanf("%f", &(ptr_hold_dist_travel->dist_travel2D.GPSCood[i].y));
                printf("\n Please enter Coordinate GPS for %d for y", i);
                scanf("%f", &(ptr_hold_dist_travel->dist_travel2D.GPSCood[i].z));
            }
            break;
        }
        case 2:{
            //If user select 1 for Choice = 3D, loop 3 times to get 3 points of xyz,xyz,xyz coordinates
            //the value that we are scanning into in the GPSCood is a struct of 3D_Points, and inside x y z is a float.
            //So we scan %f.
            for(int i=0; i<max_size; ++i){
                printf("\n Please enter Coordinate GPS for %d for x", i);
                scanf("%f", &(ptr_hold_dist_travel->dist_travel3D.GPSCood[i].x));
                printf("\n Please enter Coordinate GPS for %d for y", i);
                scanf("%f", &(ptr_hold_dist_travel->dist_travel3D.GPSCood[i].y));
                printf("\n Please enter Coordinate GPS for %d for z", i);
                scanf("%f", &(ptr_hold_dist_travel->dist_travel3D.GPSCood[i].z));
            }
            break;
        }
    }
    printf("\n End of reading coordinates, returning");
}

void dist_cal(union Euc_dist *ptr_dist_travel,int choice)
{ 
        int i;
        //Temporary float value to store squared differences
        float temp_deltax,temp_deltay,temp_deltaz;
        //Choice to calculate 2D or 3D.
        switch (choice)
        {
                case 1: //Calculate 2D
                {       
                        ptr_dist_travel->dist_travel2D.total_distance=0.0; //Initialize 2D total dist = 0;
                        for (i=0;i<(max_size-1);++i)
                        {
                                //distance calculation,  dist_travel2D.GPSCood[i+1].x (mean x2) - dist_travel2D.GPSCood[i].x (x1) , then store in deltax
                                temp_deltax=pow((ptr_dist_travel->dist_travel2D.GPSCood[i+1].x-ptr_dist_travel->dist_travel2D.GPSCood[i].x),2);
                                //distance calculation,  dist_travel2D.GPSCood[i+1].x (mean y2) - dist_travel2D.GPSCood[i].x (y1) , then store in deltay
                                temp_deltay=pow((ptr_dist_travel->dist_travel2D.GPSCood[i+1].y-ptr_dist_travel->dist_travel2D.GPSCood[i].y),2);
                                //Take the value of y2-y1 and x2-x1 and square them to get the distance between points.
                                ptr_dist_travel->dist_travel2D.distance2D[i]=sqrt(temp_deltax+temp_deltay);
                                //Add the distance to total_distance for summing
                                ptr_dist_travel->dist_travel2D.total_distance += ptr_dist_travel->dist_travel2D.distance2D[i];
                        }
                        break;
                                
                }
                case 2://Calculate 3D
                {
                         ptr_dist_travel->dist_travel3D.total_distance=0.0;
                         for (i=0;i<(max_size-1);++i)
                        {
                                temp_deltax=pow((ptr_dist_travel->dist_travel3D.GPSCood[i+1].x-ptr_dist_travel->dist_travel3D.GPSCood[i].x),2);
                                temp_deltay=pow((ptr_dist_travel->dist_travel3D.GPSCood[i+1].y-ptr_dist_travel->dist_travel3D.GPSCood[i].y),2);
                                //Same thing as 2D, but 3D has Z-coordinate (z2 - z1)       
                                temp_deltaz=pow((ptr_dist_travel->dist_travel3D.GPSCood[i+1].z-ptr_dist_travel->dist_travel3D.GPSCood[i].z),2);
                                //Square x2-x1, y2-y1 - z2-z1
                                ptr_dist_travel->dist_travel3D.distance3D[i]=sqrt(temp_deltax+temp_deltay+temp_deltaz);
                                ptr_dist_travel->dist_travel3D.total_distance += ptr_dist_travel->dist_travel3D.distance3D[i];
                        }
                        break;
                }
        }
}

void print_dist(union Euc_dist *ptr_dist_travel,int choice)
{
        int i;

        printf("\n------------------------------------------------------------");
        printf("\nDistance travelled between two GPSpoints in %d dimension",choice+1);
        printf("\n------------------------------------------------------------");
        switch (choice)
        {
                case 1:
                {
                        for (i=0;i<(max_size-1);++i)
                        {
                                printf("\nDistance travelled between point %d and point %d is %f ",i+1,i+2,ptr_dist_travel->dist_travel2D.distance2D[i]);
                        }
                        printf("\n Total distance travelled in 2D dimension is %f : ", ptr_dist_travel->dist_travel2D.total_distance);
                        break;
                }
                case 2:
                {
                        for (i=0;i<(max_size-1);++i)
                        {
                                printf("\nDistance travelled between point %d and point %d is %f ",i+1,i+2,ptr_dist_travel->dist_travel3D.distance3D[i]);
                        }
                        printf("\n Total distance travelled in 3D dimension is %f : ",ptr_dist_travel->dist_travel3D.total_distance);
                        break;
                }
        }
}