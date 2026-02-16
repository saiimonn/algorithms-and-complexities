#include <stdio.h>
#include "../../headers/arr.h"

void selectionSortAsc(int[], int);
void selectionSortDesc(int[], int);

int main() {
    int arr[] = {29, 18, 42, 10, 48};
    int len = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArr(arr, len);

    selectionSortAsc(arr, len);
    printf("Sorted Ascending: ");
    printArr(arr, len);

    selectionSortDesc(arr, len);
    printf("Sorted Descending: ");
    printArr(arr, len);

    return 0;
}

void selectionSortAsc(int arr[], int size) {
    for(int i = 0; i < size - 1; i++){ 
        int min = i;
        
        for (int j = i + 1; j < size; j++){ 
            if(arr[j] < arr[min]) min = j;
        }
        
        swap(&arr[i], &arr[min]);
    }
}

void selectionSortDesc(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        int max = i;
        
        for(int j = i + 1; j < size; j++) {
            if(arr[j] > arr[max]) max = j;
        }
        
        swap(&arr[i], &arr[max]);
    }
}