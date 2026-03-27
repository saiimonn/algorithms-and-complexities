#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../headers/arr.h"

typedef struct {
    int *elems;
    int count;
} Array;

void countingSort(Array *);

int main() {
    int values[] = {3, 1, 7, 2, 2, 3, 4};
    Array arr = {values, 7};
    
    countingSort(&arr);
    
    for(int i = 0; i < arr.count; i++){
        printf("%d ", arr.elems[i]);
    }
    printf("\n");
}

void countingSort(Array *arr) {
    if (arr->count > 0) {
        // 1: find range (max - min + 1)
        int i;
        int min = arr->elems[0];
        int max = arr->elems[0];
        for(i = 1; i < arr->count; i++) {
            if(arr->elems[i] < min) min = arr->elems[i];
            if(arr->elems[i] > max) max = arr->elems[i];
        }

        int range = max - min + 1;

        // 2: create count array
        int *dict = (int*)calloc(range, sizeof(int));

        // 3: fill up count dict
        for(int i = 0; i < arr->count; i++) {
            int index = arr->elems[i] - min;
            dict[index] += 1;
        }

        // 4: get cumulative sums
        for(int i = 1; i < range; i++) {
            dict[i] += dict[i - 1];
        }

        // 5: build output array
        int *output = (int*)malloc(arr->count * sizeof(int));

        if(output != NULL) {
            int index;
            for(int i = arr->count - 1; i >= 0; i--) {
                index = arr->elems[i] - min;
                output[--dict[index]] = arr->elems[i];
            }
            memcpy(arr->elems, output, sizeof(int) * arr->count);
        }
    }
}