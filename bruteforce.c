#include<stdio.h>
#include<stdlib.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int bruteforce(int capacity, int weights[], int values[], int n)
{
    if ( n == 0 || capacity == 0)
    return 0;

    if (weights[n-1] > capacity)
    {
        return bruteforce(capacity , weights, values, n-1); 
    }

    else
    {
        int value_with_item = values[n-1] + bruteforce(capacity - weights[n-1],weights,values,n-1);
        int value_without_item = bruteforce(capacity,weights,values,n-1);
        return max(value_with_item,value_without_item);
    }
}

int main()
{
    int values[] = {};
}