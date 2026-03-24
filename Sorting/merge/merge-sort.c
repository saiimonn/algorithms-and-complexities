#include <stdio.h>
#include <stdlib.h>
#include "../../headers/arr.h"

void mergeSort(int [], int);
void merge(int [], int, int [], int []);

int main(){
    int arr[] = {29, 18, 42, 10, 48};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    mergeSort(arr, size);
    
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int size, int left[], int right[]) {
    int leftSize = size / 2;
    int rightSize = size - leftSize;
    
    int i = 0, l = 0, r = 0;
    
    while(l < leftSize && r < rightSize) {
        if(left[l] <= right[r]) arr[i++] = left[l++];
        else arr[i++] = right[r++];
    }
    
    while(l < leftSize) arr[i++] = left[l++];
    while(r < rightSize) arr[i++]  = right[r++];
}

void mergeSort(int arr[], int size) {
    if (size <= 1) return;
    
    int mid = size / 2;
    int *left = (int*)malloc(sizeof(int) * mid);
    int *right = (int*)malloc(sizeof(int) * (size - mid));
    
    for(int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    
    for(int i = 0; i < size - mid; i++) {
        right[i] = arr[i + mid];
    }
    
    mergeSort(left, mid);
    mergeSort(right, size - mid);
    merge(arr, size, left, right);
    free(left);
    free(right);
}