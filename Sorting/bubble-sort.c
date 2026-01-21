#include <stdio.h>

void bubbleSortAsc(int [], int);
void bubbleSortDesc(int [], int);
void read(int[], int);

int main() {
    int arr[] = {29, 18, 42, 10, 48};
    
    int len = sizeof(arr) / sizeof(arr[0]);
    bubbleSortAsc(arr, len);
    read(arr, len);
    
    bubbleSortDesc(arr, len);
    read(arr, len);
}

void bubbleSortAsc(int arr[], int size) {
    for (int i = 0; i < size; i++){ 
        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }   
}

void bubbleSortDesc(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void read(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}