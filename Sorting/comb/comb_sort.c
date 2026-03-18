#include <stdio.h>
#include <stdbool.h>

int getNextGap(int gap) {
    gap = (gap * 10) / 13;
    return (gap < 1) ? 1 : gap;
}

void combSort(int a[], int n) {
    int gap = n;
    bool swapped = true;
    while (gap != 1 || swapped) {
        gap = getNextGap(gap);
        swapped = false;
        for (int i = 0; i < n - gap; i++) {
            if (a[i] > a[i + gap]) {
                int temp = a[i];
                a[i] = a[i + gap];
                a[i + gap] = temp;
                swapped = true;
            }
        }
    }
}

int main() {
    int arr[] = {8, 4, 1, 56, 3, -44, 23, -6, 28, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    combSort(arr, n);
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    return 0;
}