#include <stdio.h>
#include "../../headers/arr.h"

void gnomeSort(int [], int);

int main() {
    int arr[] = {29, 18, 42, 10, 48};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    gnomeSort(arr, size);
    
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// trav = 1
// 10, 18, 29, 42, 48

void gnomeSort(int arr[], int size) {
    int trav = 0;
    
    while(trav < size) {
        if (trav == 0 || arr[trav - 1] <= arr[trav]) {
            trav++;
        } else {
            swap(&arr[trav], &arr[trav - 1]);
            trav--;
        }
    }
}