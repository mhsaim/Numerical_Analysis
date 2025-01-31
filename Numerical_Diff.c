#include<stdio.h>
#include<math.h>

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

    printf("\nForward Difference Table:\n");
    for(int i=0;i<n;i++)
    {
        printf("%0.4f\t",x[i]);
        for(int j=0;j<n-i;j++)
        {
            printf("%0.4f\t",y[i][j]);
        }
        printf("\n");
    }

    double h=x[1]-x[0];
    double z;
    z=(1.0/h)*(y[1][1]-(1.0/2.0)*y[1][2]+(1.0/3.0)*y[1][3]-(1.0/4.0)*y[1][4]+(1.0/5.0)*y[1][5]);
    printf("%lf",z);

    return 0;
}

