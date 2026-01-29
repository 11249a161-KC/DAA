#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int binarySearch(int arr[], int n, int x) 
{
    int low = 0;
    int high = n-1;
    while (low <= high) 
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] < x)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}

void bubbleSort(int* arr, int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() 
{
    int n = 10000;
    int arr[n];
    clock_t start, end;
    double cpu_time_used;
    
    srand(time(NULL));

    for(int i = 0; i<n; i++)
    {
        arr[i] = rand() % 1000;
        //printf("%d,",arr[i]);
    }

    start = clock();
    bubbleSort(arr,n);
    end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    int random = rand() % n;
    int x = arr[random];

    printf("Searching for key: %d\n", x);

    start = clock();
    int result = binarySearch(arr, n, x);
    end = clock();

    if(result == -1)
    {
        printf("Element is not present in array");
    }
    else
    { 
        printf("%lfElement is present at index %d",cpu_time_used ,result);
    }

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nTime taken for sort: %f seconds\n", time_taken);
    printf("Time taken for search: %f seconds\n", cpu_time_used);

    return 0;

}