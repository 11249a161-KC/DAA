#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 1. User-defined function (Iterative)
unsigned long long iterativeFactorial(int n) {
    unsigned long long res = 1;
    for (int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

// 2. User-defined function (Recursive)
unsigned long long recursiveFactorial(int n) {
    if (n <= 1) return 1;
    return n * recursiveFactorial(n - 1);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    int n = rand() % 10;
    int iterations = 100000;
    clock_t start, end;
    unsigned long long result;

    printf("Randomly selected n: %d\n", n);
    printf("Executing each method %d times...\n\n", iterations);

    // --- Method A: Iterative Function ---
    start = clock();
    for (int i = 0; i < iterations; i++) {
        result = iterativeFactorial(n);
    }
    end = clock();
    printf("Iterative Function Time: %f\n", (double)(end - start));

    // --- Method B: Recursive Function ---
    start = clock();
    for (int i = 0; i < iterations; i++) {
        result = recursiveFactorial(n);
    }
    end = clock();
    printf("Recursive Function Time: %f\n", (double)(end - start));

    // --- Method C: Direct Loop in Main ---
    start = clock();
    for (int i = 0; i < iterations; i++) {
        result = 1;
        for (int j = 1; j <= n; j++) {
            result *= j;
        }
    }
    end = clock();
    printf("Direct Loop in Main Time: %f\n", (double)(end - start));

    printf("\nFinal calculated value: %llu\n", result);

    return 0;
}