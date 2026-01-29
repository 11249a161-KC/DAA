#include<stdio.h>
#include<stdlib.h>

int isPrime(int num) {
    if (num <= 1) return 0; 
    
    for (int j = 2; j * j <= num; j++) {
        if (num % j == 0) {
            return 0; 
        }
    }
    return 1;
}

int main()
{
    int data[100];
    int i;
    int n = 100;

    for(i = 0; i<n; i++)
    {
        data[i] = rand() % 100;
        printf("\n%d\n",data[i]);
    }
}