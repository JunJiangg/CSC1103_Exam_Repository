#include <stdio.h>
#include <string.h>
#define max_size 100
//reason of using char *first_str" instead of a array of char:
//*first_str is known as pointer variable. these allow u to increment the address of each caharacter


//The issue with this algorithm comparison, is if the first string is long than the 2nd string or vice versa.
//It will be pre-terminated.
//E.g. if the first string is shorter than the 2nd string, there will be some letters that the 2nd string wont be compared.
//should use fgets instead of gets -> due to security issue, gets has no memory restriction of message. but fgets does with size of message


int strcmp1(const char *first_str, const char *second_str);

int main()
{
    static char first_str[max_size]="ABCD";
    static char second_str[max_size]="AB";
    int result,result1;
    printf(" \nEnter the first string :");
    gets(first_str);
    printf(" \nEnter the second string :");
    gets(second_str);
    printf("\n\nFirst string = |%s| \n", first_str);
    printf("\nSecond string = |%s| \n\n", second_str);
    result=strcmp(first_str,second_str);
    printf("\nresult using string library string compare function: %d\n",result);
    result1=strcmp1(first_str,second_str);
    printf("\nresult using own string compare function: %d\n",result1);
}
/********************************************************/
/* strcmp1.c - own version program of compare string    */
/*             using pointer                            */   
/*     asssume string 1 length >string 2 length         */                                                             
/****************************************************** */
int strcmp1(const char *first_str, const char *second_str)
{
    int result=0;
    while (*first_str)
    {
        /*if characters different or end of second strings*/
        if (*first_str!=*second_str)
            {
                /*return the ASCII difference after converting char* to unsigned char**/
                result+=(*(const unsigned char*)first_str-*(const unsigned char*)second_str); 
            }
            first_str++;
            second_str++;
    }
    return (result);
}
