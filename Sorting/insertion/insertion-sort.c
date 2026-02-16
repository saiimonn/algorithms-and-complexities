#include <stdio.h>
#include "../../headers/arr.h"

void insertionSort(int [], int);

int main() {
    int arr[] = {31, 34, 42, 10, 42, 18};
    int size = sizeof(arr) / sizeof(int);

    insertionSort(arr, size);
    printArr(arr, size);
}

void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && key < arr[j]) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}