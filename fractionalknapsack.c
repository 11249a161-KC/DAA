#include<stdio.h>

int main()
{
    int n,i,j;
    float w[10],p[10],temp,ratio[10],capacity,profit=0;

    printf("Entern number of items: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter weight and profit of item %d: ",i+1);
        scanf("%f%f",&w[i],&p[i]);
        ratio[i] = p[i]/w[i];
    }

    printf("Enter knapsack capacity: ");
    scanf("%f",&capacity);

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(ratio[i] < ratio[j])
            {
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;
                temp = w[i];
                w[i] = w[j];
                w[j] = temp;
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        if(w[i] <= capacity)
        {
            profit += p[i];
            capacity -= w[i];
        }
        else
        {
            profit += ratio[i] * capacity;
        }
    }
    printf("Maximum profit: %.2f\n", profit);
    return 0;
}