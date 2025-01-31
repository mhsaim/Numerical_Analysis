#include<stdio.h>
#include<math.h>
float f(float x)
{
    return x*x-7;
}
bisection(float a, float b, float tol)
{
    float c;
    int iter=0;
    if(f(a)*f(b)>0)
    {
        printf("\nIvalid Interval");
        return;
    }
    printf("\nIter \ta \tb \tc \tf(c)");

    do{
            c=(a+b)/2.0;
            printf("\n%d \t%f \t%f \t%f \t%f",iter,a,b,c,f(c));
    if(fabs(c)<tol)
        break;
    else if(f(a)*f(c)<0)
        {
            b=c;

        }
    else a=c;
    iter++;


    }
    while(fabs(b-a)>tol);
    printf("\nthe root is: %f",c);


}

int main()
{
    float a,b;
    printf("Enter the Interval[a,b]: ");
    scanf("%f %f",&a,&b);
    float tol;
    printf("\nEnter tolerence: ");
    scanf("%f",&tol);
    bisection(a,b,tol);



    return 0;
}
