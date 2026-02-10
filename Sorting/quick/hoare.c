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
    if(low < high) {
        int i = low - 1;
        int j = high + 1;

        int pivot = arr[low];

        while (i < j) {
            do { 
                i++;
            } while(arr[i] < pivot);

            do {
                j--;
            } while(arr[j] > pivot);

            if(i < j) {
                swap(arr + i, arr + j);
            }
        }

        quickSort(arr, low, j);
        quickSort(arr, j + 1, high);
    }
}