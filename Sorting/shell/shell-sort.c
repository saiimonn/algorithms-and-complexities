#include <stdio.h>
#include "../../headers/arr.h"

void shellSort(int [], int);

int main() {
    int arr[] = {29, 18, 42, 10, 48};
    int len = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArr(arr, len);

    shellSort(arr, len);
    printf("Sorted: ");
    printArr(arr, len);

    return 0;
}

void shellSort(int arr[], int size) {
    for(int gap = size / 2; gap < 0; gap /= 2) {
        for(int i = 0; i < size; i++) {
            int temp = arr[i], j;
            
            for(j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            
            if (j != i) {
                arr[j] = temp;
            }
        }
    }
}