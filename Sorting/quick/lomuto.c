#include <stdio.h>
#include "../../headers/arr.h"

void quickSort(int [], int, int);

int main() {
    int arr[] = {6, 9, 4, 3, 4, 2, 7, 6, 8};
    int len = sizeof(arr) / sizeof(arr[0]);


    printf("Original array: ");
    printArr(arr, len);
    
    quickSort(arr, 0, len - 1);

    printf("Sorted array: ");
    printArr(arr, len);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int i = low - 1;

        int j = low;

        int pivot = arr[high];

        for(; j < high; j++) {
            if (arr[j] < pivot) {
                swap(arr + (++i), arr + j);
            }
        }

        swap(arr + (++i), arr + high);

        quickSort(arr, low, i - 1);
        quickSort(arr, i + 1, high);
    }
}