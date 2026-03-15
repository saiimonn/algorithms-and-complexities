#include <stdio.h>
#include <stdlib.h>
#include "../../headers/arr.h"

void quickSort(int [], int, int);

int comparisonCtr = 0;

int main() {
    int arr[] = {6, 9, 4, 3, 4, 2, 7, 6, 8};
    int len = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArr(arr, len);
    
    quickSort(arr, 0, len - 1);

    printf("Sorted array: ");
    printArr(arr, len);

    printf("\nComparison Counter: %d", comparisonCtr);
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int n = high - low + 1;

    int *temp = (int*)malloc(n * sizeof(int));
    int idx = 0;

    for (int i = low; i <= high; i++) {
        comparisonCtr++;
        if (arr[i] <= pivot) {
            temp[idx++] = arr[i];
        }
    }

    int pi = low + idx - 1;

    for (int i = low; i <= high; i++) {
        comparisonCtr++;
        if (arr[i] > pivot) {
            temp[idx++] = arr[i];
        }
    }

    for (int i = 0; i < n; i++) {
        arr[low + i] = temp[i];
    }

    free(temp);
    return pi;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}