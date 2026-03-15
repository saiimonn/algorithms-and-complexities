#include <stdio.h>
#include "../../headers/arr.h"

void quickSort(int [], int, int);

int comparisons = 0;

int main() {
    // ===== BEST CASE =====
    int bestCase[] = {5, 3, 7, 2, 4, 6, 8}; // Balanced splits
    int lenBest = sizeof(bestCase)/sizeof(bestCase[0]);
    comparisons = 0;

    printf("BEST CASE:\nOriginal array: ");
    printArr(bestCase, lenBest);

    quickSort(bestCase, 0, lenBest-1);

    printf("Sorted array: ");
    printArr(bestCase, lenBest);
    printf("Total comparisons: %d\n\n", comparisons);

    // ===== AVERAGE CASE =====
    int avgCase[] = {6, 9, 4, 3, 4, 2, 7, 6, 8}; // Random order
    int lenAvg = sizeof(avgCase)/sizeof(avgCase[0]);
    comparisons = 0;

    printf("AVERAGE CASE:\nOriginal array: ");
    printArr(avgCase, lenAvg);

    quickSort(avgCase, 0, lenAvg-1);

    printf("Sorted array: ");
    printArr(avgCase, lenAvg);
    printf("Total comparisons: %d\n\n", comparisons);

    // ===== WORST CASE =====
    int worstCase[] = {1,2,3,4,5,6,7,8,9}; // Sorted ascending, pivot first element
    int lenWorst = sizeof(worstCase)/sizeof(worstCase[0]);
    comparisons = 0;

    printf("WORST CASE:\nOriginal array: ");
    printArr(worstCase, lenWorst);

    quickSort(worstCase, 0, lenWorst-1);

    printf("Sorted array: ");
    printArr(worstCase, lenWorst);
    printf("Total comparisons: %d\n", comparisons);

    return 0;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;

    while (1) {
        do {
            i++;
            comparisons++; // Count arr[i] < pivot
        } while(arr[i] < pivot);

        do {
            j--;
            comparisons++; // Count arr[j] > pivot
        } while(arr[j] > pivot);

        if (i >= j) return j;

        swap(&arr[i], &arr[j]);
    }
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}