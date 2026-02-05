#include<stdio.h>
void perm(int [], int, int);
void perm(int a[],int start, int stop)
{
    int temp,i;
    if (start==stop)
    {
        printf("Total space complexity:%d\n",sizeof(int)*stop+sizeof(start)+sizeof(stop)+sizeof(i)+sizeof(temp));
        for(int i=0;i<stop;i++)
        {
            printf("%d\t",a[i]);
        }
        printf("\n");
    }
    else
    {
        for (int i=start;i<stop;i++)
        {
            temp = a[start];
            a[start] = a[i];
            a[i] = temp;
            perm(a,start+1,stop);
            temp = a[start];
            a[start] = a[i];
            a[i] = temp;
        }
    }
}

int main()
{
    int n,arr[10];
    printf("Enter total number of elements\n");
    scanf("%d",&n);
    printf("enter each element value");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        printf("\n");
    }
    perm(arr, 0, n);

    return 0;
}