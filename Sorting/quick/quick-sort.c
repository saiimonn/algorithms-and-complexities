#include <stdio.h>

int partition(int [], int, int);
void swap(int *, int *);
void quickSort(int [], int, int);
void read(int [], int);

int main() {
    int data[] = {8, 7, 2, 1, 0, 9, 6};

    int len = sizeof(data) / sizeof(data[0]);

    printf("Unsorted: ");
    read(data, len);

    quickSort(data, 0, len - 1);

    printf("Sorted Asc: ");
    read(data, len);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];

    int i = (low - 1);

    for(int j = low; j < high; j++) {
        if(arr[j] <= pivot) {
            i++;

            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void read(int arr[], int len) {
    for(int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
}