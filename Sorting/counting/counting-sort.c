#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../headers/arr.h"

void countingSort(int [], int);

int main() {
    int arr[] = {29, 18, 42, 10, 48};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    countingSort(arr, size);
    
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void countingSort(int arr[], int size) {
    int min = arr[0], max = arr[0], range;
    
    for(int i = 0; i < size; i++) {
        min = (arr[i] < min) ? arr[i] : min;
        max = (arr[i] > max) ? arr[i] : max;
    }
    
    range = max - min + 1;
    
    int *count = calloc(range, sizeof(int));
    
    for(int i = 0; i < size; i++) count[arr[i] - min]++;
    
    for(int i = 1; i < range; i++) count[i] += count[i - 1];
    
    for(int i = range - 1; i > 0; i--) count[i] = count[i - 1];
    
    count[0] = 0;
    
    int *output = malloc(sizeof(int) * size);
    
    for(int i = 0; i < size; i++) {
        output[count[arr[i] - min]++] = arr[i];
    }
    
    memcpy(arr, output, sizeof(int) * size);
    free(output);
    free(count);
}