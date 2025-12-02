#include <stdio.h>
#include <math.h>

#define PI 3.141592

int main()
{
    float delta,sigma,mu,x,xmin,xmax;
    double fx,sum;
    //Gausian is a probabilty thing.
    //The entire code plot the probability of something happening. in this case is weather temperature
    //In prev test, base on weather temperature.
    mu=24; //the average, the most common temperature to occur is 24 degree celsius             
    sigma=0.5; 
    //Sigma, this is the standard deviation. which indicate how much the temperature varies
    //0.5 means varies mostly close to 24, very unlikely to see 22 or 26 degree
    //Curve becomes narrow means, temperature don vary much
    delta=0.1;
    //Delta is the step size of each probabilty measured.
    //if is 0.01, then from xMin, 22.5, next step size is f(22.51), f(22.52)
    //0.01 per step measured probabilty          
    xmin=22.5; // mu - 3(sigma)         
    xmax=25.5; // mu + 3(sigma) 
    sum=0;     
    
    //Very important thing to note here is, if x-mu is too huge difference. the value may turn 0.00000e+00
    //This is normal and is not wrong. is just that at that step size, x is too far away from the central
    //And the exponent formula used makes the value too huge to be displayed because double data type cant hold the value.
    printf("\n Normal Distribution of temperature ranging from 22.5 degree cel to 25.5 degree cel ");
    printf("\n *********************************************************************");
    printf("\n Value of x           Value of f(t)");
    printf("\n __________________________________");
    x=xmin;
    while (x<=xmax)
    {
        fx=1/(sqrt(2*PI)*sigma)*exp(-0.5*pow((x-mu),2)/pow(sigma,2));
        printf("\n %f                   %e",x,fx);
        x+=delta;
        sum+=(fx*delta); //this approximates the total probability of xMin to xMax because gausian is under curve = 1
        //So if the sum probability is very close 1, it means the temperature really varies around 24 degree very closely
    }
    printf("\n sum=%e\n",sum);
    return 0;

}