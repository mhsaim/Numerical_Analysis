#include<stdio.h>
#include<math.h>
float fact(int n)
{
    if(n==0 || n==1)
        return 1;
    else
        return n*fact(n-1);
}
float calu(float u, int n)
{
    float temp=u;
    for(int i=1;i<n;i++)
    {
        temp=temp*(u-i);
    }
    return temp;

}

void interpolate(float x[],float y[][10],int n, float value)
{
    float sum=y[0][0];
    float u=(value-x[0])/(x[1]-x[0]);
    for(int i=1;i<n;i++)
    {
        sum +=calu(u,i)*y[0][i]/fact(i);
    }
    printf("Interpolated value at %.2f is %.2f\n", value, sum);
}



int main()
{
    int n;
    printf("Enter the number of data point: ");
    scanf("%d",&n);
   float x[n],y[n][10];

    printf("\nEnter the value of x: ");
    for(int i=0;i<n;i++)
    {
        scanf("%f",&x[i]);
    }

    printf("\nEnter the value of y: ");
    for(int i=0;i<n;i++)
    {
        scanf("%f",&y[i][0]);
    }


    for(int col=1;col<n;col++)
    {
        for(int row=0;row<n-col;row++)
        {
            y[row][col]=y[row+1][col-1]-y[row][col-1];
        }
    }

    printf("\nForward Difference Table: ");
    for(int i=0;i<n;i++)
    {
        printf("%0.3f\t",x[i]);
        for(int j=0;j<n-i;j++)
        {
            printf("%0.3f\t",y[i][j]);
        }
        printf("\n");
    }

    float value;
    printf("\nEnter the value of interpolate: ");
    scanf("%f",&value);
    interpolate(x,y,n,value);





    return 0;
}
