#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    printf("\nEnter the size of array: ");
    scanf("%d",&n);
    float a[10][10],u[10][10]={0},l[10][10]={0},b[10],x[10],y[10];
    printf("\nEnter the array of element: ");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%f",&a[i][j]);
        }
    }
    printf("\nEnter the element of b matrix: ");
    for(int i=0;i<n;i++)
    {
        scanf("%f",&b[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            u[i][j]=a[i][j];
            for(int k=0;k<i;k++)
            {
                u[i][j]-=l[i][k]*u[k][j];
            }
        }
        for(int j=i;j<n;j++)
        {
            if(i==j)
            {
                l[i][i]=1;
            }
            else{
                l[j][i]=a[j][i];
                for(int k=0;k<i;k++)
                {
                    l[j][i]-=l[j][k]*u[k][i];
                }
                l[j][i]/=u[i][i];
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%f ",l[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        {
            printf("%f ",u[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<n;i++)
    {
        y[i]=b[i];
        for(int j=0;j<i;j++)
        {
            y[i]-=l[i][j]*y[j];
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        x[i]=y[i];
        for(int j=i+1;j<n;j++)
        {
            x[i]-=u[i][j]*x[j];
        }
        x[i]/=u[i][i];
    }
    for(int i=0;i<n;i++)
    {
        printf("\n%f",x[i]);
    }
    return 0;
}
