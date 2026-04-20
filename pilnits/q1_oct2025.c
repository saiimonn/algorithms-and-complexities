#include <stdio.h>

int sum(int [], int, int);

int main() {
    int arr[] = {10, 15, 20, 25, 30};
    printf("%d", sum(arr, 1, 3));
}

int sum(int arr[], int k, int m) {
    int s = 0;
    int i = k;
    while(i <= m) {
        if(arr[i] % 2 == 0) s += arr[i];
        i += 1;
    }
    return s;
}