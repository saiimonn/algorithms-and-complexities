#include <stdio.h>
#include <stdbool.h>
#include "../../headers/arr.h"

void combSort(int arr[], int size) {
    bool isSorted = false;

    for(int gap = size / 1.3; gap > 0 || !isSorted; gap /= 1.3) {
        if(gap < 1) gap = 1;

        isSorted = true;

        for(int i = gap; i < size; i++) {
            if(arr[i - gap] > arr[i]) {
                swap(&arr[i - gap], &arr[i]);
                isSorted = false;
            }
        }
    }
}

int main() {
    int arr[] = {8, 4, 1, 56, 3, -44, 23, -6, 28, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    combSort(arr, n);
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}