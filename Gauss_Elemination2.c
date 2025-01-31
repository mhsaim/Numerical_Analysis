#include<stdio.h>
#include<math.h>

int main()
{
    int n;
    printf("Enter Matrix size (number of equations): ");
    scanf("%d",&n);
    double arr[n][n+1];
    double x[n];

    printf("Enter the elements of the Matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n+1;j++)
        {
            printf ("row [%d] column [%d]:",i+1,j+1);
            scanf("%lf",&arr[i][j]);
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            double f=arr[j][i]/arr[i][i];
            for(int k=i;k<n+1;k++)
            {
                arr[j][k]=arr[j][k]-f*arr[i][k];

            }
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        x[i]=arr[i][n];
        for(int j=i+1;j<n;j++)
        {
            x[i]=x[i]-arr[i][j]*x[j];
        }
       x[i]=x[i]/arr[i][i];
    }
    printf("Answer is:\n");
    for(int i=0;i<n;i++)
    {
        printf("x[%d]=%f\n",i+1,x[i]);

    }
  return 0;
}
