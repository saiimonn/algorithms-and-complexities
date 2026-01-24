#include <stdio.h>

void selectionSortAsc(int[], int);
void selectionSortDesc(int[], int);
void read(int[], int);

int main() {
    int arr[] = {29, 18, 42, 10, 48};
    int len = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    read(arr, len);

    selectionSortAsc(arr, len);
    printf("Sorted Ascending: ");
    read(arr, len);

    selectionSortDesc(arr, len);
    printf("Sorted Descending: ");
    read(arr, len);

    return 0;
}

void selectionSortAsc(int arr[], int size) {
    for(int i = 0; i < size - 1; i++){ 
        int min = i;
        
        for (int j = i + 1; j < size; j++){ 
            if(arr[j] < arr[min]) min = j;
        }
        
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void selectionSortDesc(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        int max = i;
        
        for(int j = i + 1; j < size; j++) {
            if(arr[j] > arr[max]) max = j;
        }
        
        int temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
    }
}

void read(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}