#include<stdio.h>

int main()
{
    int w[10],p[10],n,i,j,cap,temp1;
    float up[10],temp,pri=0.0;
    printf("Enter number of items");
    scanf("%d",&n);
    printf("Enter weight of each item:");
    for(i=0;i<n,;i++)
    {
        scanf("%d",&w[i]);
    }
    printf("Enter profit of each item:");
    for(i=0;i<n,;i++)
    {
        scanf("%d",&p[i]);
    }
    printf("Enter capacity of the bag:");
    scanf("%d",&cap);
    for(i=0;i<n;i++)
    {
        up[i] = 1.0*(p[i]/w[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(up[i]<up[j])
        }
    }
}
