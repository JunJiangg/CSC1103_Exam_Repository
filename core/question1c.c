#include <stdio.h> 
 
float x,y,z,a,b,c;

int main(){
    int d;
    x=1.7e-30;
    y=2.0e-8;
    z=2.01e38;
    a=x*y+d;
    b=y/z;
    c=3.4e38+b;

    printf("a value is :%e\n", a);
    printf("b value is :%e\n", b);
    printf("c value is :%e\n", c);
}