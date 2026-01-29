#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int linearSearch(int* arr, int n, int key) 
{
    for 
    (int i = 0; i < n; i++) 
    {
        if (arr[i] == key) 
        {
            return i;
        }
    }
    return -1; 
}

int main() {
    int n = 100000;
    int arr[n];
    int key;
    clock_t start, end;
    double cpu_time_used;

    srand(time(NULL));
    //printf("z%d",sizeof(int));
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() %1000;
        //printf("%d,",arr[i]);
    }

    int random = rand() % n;
    key = arr[random];
    

    printf("Searching for key: %d\n", key);

    start = clock();
    int result = linearSearch(arr, n, key);
    end = clock();

    cpu_time_used = ((double) (end )- (double)(start))  / CLOCKS_PER_SEC;

    if (result != -1) 
    {
        printf("%lf\nKey Found at Index: %d\n",cpu_time_used , result);
    }
    else
    {
        printf("Key Not Found\n");
        printf("%lfKey Found at Index: %d\n",cpu_time_used , result);
    }

  //  printf("Time taken for search: %lf seconds\n", cpu_time_used);

    return 0;
}