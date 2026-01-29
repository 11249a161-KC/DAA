#include <stdio.h>
#include<time.h>

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {

    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }

    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);

    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);

    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n = 64123456;
    clock_t start, end;
    printf("Steps to solve Tower of Hanoi with %d disks:\n", n);

    start = clock();
    //towerOfHanoi(n, 'A', 'C', 'B');
    end = clock();
    
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    printf("Time taken for search: %f seconds\n", cpu_time_used);
    return 0;
}