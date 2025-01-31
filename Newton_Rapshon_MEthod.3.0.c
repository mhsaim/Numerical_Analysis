#include<stdio.h>
#include<math.h>
float f(float x)
{
    return x*x*x-2*x-5;
}
float df(float x)
{
    return 3*x*x-2;
}
rapshon(float ini, float tol)
{
    float x=ini;
    float h;
    int iter=0;
    printf("Iter\t    x\t          f(x)\n");
    do{

    h=f(x)/df(x);
    printf("%d\t%.6f\t%.6f\n", iter, x, f(x));
    x=x-h;
    iter++;
    }
    while(fabs(h)>tol);
    printf("\nThe value is: %f",x);
}

int main()
{
    float ini,tol;
    printf("Enter the initial value: ");
    scanf("%f",&ini);
    printf("\nEnter tolerance:");
    scanf("%f",&tol);
    rapshon(ini,tol);




    return 0;
}
