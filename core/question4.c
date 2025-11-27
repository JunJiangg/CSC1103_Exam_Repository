#include <stdio.h>

void cube(void);

int a=2;
static int b;

int main(){
    printf("\n Value of a in main=%d",a); 
    printf("\n Value of b in main=%d",b); 
    cube(); 

    printf("\n Value of a in main=%d",a); 
    printf("\n Value of b in main=%d",b); 
    cube(); 

    printf("\n Value of a in main=%d",a); 
    printf("\n Value of b in main=%d",b); 
    cube(); 

    return 0;
}

void cube(void) 
{ 
    static int a;        
    int b=2;
    a *=a*a;
    b *=b*b;
    printf("\n Value of a in cube function =%d",a); 
    printf("\n Value of b in cube function =%d",b); 
} 
 
