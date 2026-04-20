#include <stdio.h>

int findMode(int [], int);

int main() {
    int arr[] = {2, 1, 1, 9, 6, 6, 2, 5, 6};
    int len = sizeof(arr) / sizeof(arr[0]);
    printf("%d", findMode(arr, len));
}

int findMode(int arr[], int n) {
    int m = arr[0];
    int mc = 1;
    int c, i, j;
    
    for(i = 0; i < n - 1; i++) {
        c = 0;
        for(j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) c++;
        }
        
        if(c > mc) {
            mc = c;
            m = arr[i];
        }
    }
    
    return m;
}