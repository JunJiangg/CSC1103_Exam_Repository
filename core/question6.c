#include <stdio.h>
#include <math.h>

int n = 0;

int factorial(int inputInt){
    if(inputInt == 0 || inputInt == 1){
        printf("input interger value is 1, returning 1\n");
        return 1;
    }
    else{
        return inputInt * factorial(inputInt -1);
    }
}

int main(void){

    printf("Enter a number n to compute factorial: \n ");
    scanf("%d", &n);
    int absolute_num = abs(n);

    if(absolute_num <= 0){
        return 1;
    }
    else{
        int result = factorial(absolute_num);

         printf("Factorial result = %d \n", result);
    }
}