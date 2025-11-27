#include <stdio.h>

void square(void);

int a=2;
int b=2;


int main(){
    printf("\n Value of a in main=%d",a); 
    printf("\n Value of b in main=%d",b); 
    square(); 

    printf("\n Value of a in main=%d",a); 
    printf("\n Value of b in main=%d",b); 
    square(); 

    printf("\n Value of a in main=%d",a); 
    printf("\n Value of b in main=%d",b); 
    square(); 

    return 0;
}

void square(void) 
{ 
    static int a=2;        
    int b=2;  
    a *=a; 
    b *=b; 
    printf("\n Value of a in square function =%d",a); 
    printf("\n Value of b in square function =%d",b); 
} 
 
