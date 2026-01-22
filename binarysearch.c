#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Partition function to place the pivot in the correct position
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1);    

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// The main Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int binarySearch(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;
    int count = 0;

    while (low <= high) { 
        count++;
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            printf("\nSearch comparisons: %d", count); // Moved inside for success case
            return mid;
        }

        if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    printf("\nSearch comparisons: %d", count);
    return -1;
}

int main() {
    int data[10000];
    int i;
    int n = 10000;
    
    srand(time(NULL));

    for(i = 0; i < n; i++) {
        data[i] = rand() % 50000; 
    }
    
    // --- Sorting Section ---
    clock_t start_sort = clock();
    quickSort(data, 0, n - 1);
    clock_t end_sort = clock();
    
    // Calculate the missing variable
    double time_taken_sort = ((double)(end_sort - start_sort)) / CLOCKS_PER_SEC;
    
    printf("Sorted Array:\n");
    for(i = 0; i < 10000; i++) {
        printf("%d ", data[i]);
        if ((i + 1) % 10 == 0) printf("\n");
    }
    
    int target = data[rand() % n];
    printf("Target element to find: %d", target);
    
    clock_t start_search = clock();
    int result = binarySearch(data, n, target);
    clock_t end_search = clock();
    
    double time_taken_search = ((double)(end_search - start_search)) / CLOCKS_PER_SEC;

    printf("\nQuick Sort Time: %f seconds\n", time_taken_sort);
    printf("Binary Search Time: %f seconds\n", time_taken_search);
    
    if (result != -1)
        printf("Element found at index: %d\n", result);
    else
        printf("Element not found in array.\n");

    return 0;
}