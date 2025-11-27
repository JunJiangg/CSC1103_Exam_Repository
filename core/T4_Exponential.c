/*
Algorithm Steps

Read the value of x.
Set limit = 1 × 10^-2.
Set term = 1, sum = 1, and n = 1.
If x < 0, set absx = -x; else set absx = x.

Repeat the following steps while term ≥ limit:
 a. term = term * absx / n
 b. sum = sum + term
 c. n = n + 1
 d. Print current term and sum.

If x < 0, then sum = 1 / sum.

Print the final value of sum.

Pseudocode:

BEGIN
    READ x
    limit ← 1 × 10^-6
    term, sum, n ← 1

    IF x < 0 THEN
        absx ← -x
    ELSE
        absx ← x
    ENDIF

    DO
        term ← term * absx / n
        sum ← sum + term
        n ← n + 1
        PRINT "sum", sum
        PRINT "term", term
    WHILE (term ≥ limit)
    END WHILE

    IF x < 0 THEN
        sum ← 1 / sum
    ELSE
        sum ← sum
    ENDIF

    PRINT "sum", sum
END



*/


#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    double x,absx,limit,term,sum,error,mexp;

    printf("\nPlease input the value of x :");
    scanf("%lf",&x);
    limit=1e-6;     /*the limit for stopping calculation*/
    term=1.0;         /*set the term to 1 for first term*/
    sum=1.0;          /*set the infinite series value to 1*/
    n=1;
    absx=x<0?-x:x;  /*if x is negative , convert to positive*/
    do 
    {
        term*=(absx/n);
        sum+=term;
        n+=1;
        printf("\nThe sum at term %d is equal to %le",n,sum);
        printf("\nThe term %d value is %le",n,term);
    }
    while((term>=limit));        /*if the term less than 1e-6, stop the computation*/
    sum=x<0?1.0/sum:sum;          /*if x is negative,answer is reciprocal of the original*/
    printf("\nThe exponential of %lf using infinite series is equal to %le",x,sum);
    mexp=exp(x);                /*calculate the exp using the math libray*/
    error=mexp-sum;             /*the error in computation using infinite series and the math libray*/
    printf("\nThe exponential of %lf using math library is equal to %le",x,mexp);
    printf("\nThe error between using infinite series and math libray exp is %le\n",error);
}