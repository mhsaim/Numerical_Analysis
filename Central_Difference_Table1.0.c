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
        for(int row=0;row<n;row++)
        {
            y[row][col]=y[row+1][col-1]-y[row][col-1];
        }
    }

    printf("\nCentral Difference Table:\n");
   for(int i=0;i<n;i++)
   {
       printf("%f\t",x[i]);
       for(int j=0;j<n-i;j++)
       {
           printf("%f\t",y[i][j]);
       }
       printf("\n");
   }

    return 0;
}
