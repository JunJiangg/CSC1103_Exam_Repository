#include <stdio.h>
#include <string.h>

int strcompare1(const char *first_str, const char *second_str);
int result = 0;

int main(){

    const char first_str[5] = "Lovee";
    const char second_str[5] = "Lov";
    //Actual use only 4 char, last one is for terminating null

    int strCmpResult = strcmp(first_str, second_str);
    //strcmp returns > 0 if first_str is bigger than second_str
    //Returns < 0 if second_str is longer than first_str
    //Returns 0 if both string are same length
    if(strCmpResult ==0){
        puts("Both String are the same length");
        printf("Both string are the same result %s and %s", first_str, second_str);
    }
    
    strcompare1(first_str, second_str);
    printf("returning result for strcompare1 %d", result);
    
}

int strcompare1(const char *first_str, const char *second_str){
    //Take note here, *(first_str) and *first_str is the same thing
    //return u the first char character in the pointer, "L" in this case
    //if u wanna print the entire word use the entire pointer first_str
    /*
    printf("\ntest value from pointer %s", first_str);
    printf("\ntest value from pointer %s", first_str+1);
    printf("\ntest value from pointer %c", first_str[0]);
    printf("\ntest from pointer %c %s", *(first_str), first_str);
    */

    
    while(*(first_str)){
        if (*(first_str) != *(second_str))
        {
            result+=(*(const unsigned char*)first_str-*(const unsigned char*)second_str);
        }
        //This 2 ++ increase the letter to check from "L" to "o"
        first_str++;
        second_str++;
    }
    return result;
    
}