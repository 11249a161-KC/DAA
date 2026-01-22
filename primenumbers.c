#include<stdio.h>
#include<stdlib.h>

int isPrime(int num) {
    if (num <= 1) return 0; // 0 and 1 are not prime
    
    // Check for divisors from 2 up to num/2
    for (int j = 2; j * j <= num; j++) {
        if (num % j == 0) {
            return 0; // It has a divisor, so it's NOT prime
        }
    }
    return 1; // It has no divisors, so it IS prime
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