/*
A Gaussian (or normal) distribution describes how values of a random variable are spread around a mean (average).
It forms the classic bell-shaped curve.

BEGIN
    mu ← 1
    sigma ← 2
    delta ← 0.5
    xmin ← -20
    xmax ← 20
    x ← xmin

    WHILE x ≤ xmax DO
        f(x) ← (1 / (sqrt(2 * π) * sigma)) * exp(-((x - mu)^2) / (2 * sigma^2))
        PRINT x, f(x)
        x ← x + delta
    END WHILE
END

*/


//  fx=1/(sqrt(2*PI)*sigma)*exp(-0.5*pow((x-mu),2)/pow(sigma,2));
//function f(x) = 1/(sqrt(2*PI)*sigma)*exp(-0.5*pow((x-mu),2)/pow(sigma,2));


#include <stdio.h>
#include <math.h>
#define PI 3.141592653589793

double calculateGaussian(float x, float mu, float sigma){
    double fx = 1/(sqrt(2*PI)*sigma)*exp(-0.5*pow((x-mu),2)/pow(sigma,2));
    return fx;
}

int main(void){
    float mu = 24;
    float sigma = 0.5;
    float xMin = 0;
    float xMax = 40;
    float x = xMin;
    
    printf("Starting gaussian calculation: \n");
    while (x <= xMax)
    {
        
        printf("\n When x = %f , the f(x) = %e :", x, calculateGaussian(x, mu, sigma));
        x += 0.01;
    }
}



/*
Key take away:
The gausian value before -38 will be 0.000000e+00 and after 38 will be 0.000000e+00

This is because the exponent power of any value +- 40 will exceed what a double f(x) can return
    -Remember that a double can only return 10^308. 
    -In our gausian fomula our exponent power is computing exp(-0.5 x (x - mu)^2)
    -So for any value that is +- 40, exp(-0.5 x (x - mu)^2) will give us around 1600, half of that is +- 800
    -which equates to exp(+-800) == 1.94 x 10-348, which exceed what double can returns. 
    -This is why the value of x +- 40 is 0.000000e+00
*/



