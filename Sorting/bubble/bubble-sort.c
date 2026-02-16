#include <stdio.h>
#include "../../headers/arr.h"

void bubbleSortAsc(int [], int);
void bubbleSortDesc(int [], int);

int main() {
    int arr[] = {29, 18, 42, 10, 48};
    
    int len = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    printArr(arr, len);
    
    bubbleSortDesc(arr, len);
    printf("Sorted Descending: ");
    printArr(arr, len);
    
    bubbleSortAsc(arr, len);
    printf("Sorted Ascending: ");
    printArr(arr, len);
}

void bubbleSortAsc(int arr[], int size) {
    for (int i = 0; i < size - 1; i++){ 
        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }   
}

void bubbleSortDesc(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j] < arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}