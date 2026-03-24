#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "../../headers/arr.h"
#include "../../headers/LL.h"

void bucketSort(int [], int);

int main() {
    int arr[] = {29, 18, 42, 10, 48};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    bucketSort(arr, size);
    
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bucketSort(int arr[], int size) {
    int numBuckets = sqrt(size);
    
    if(!numBuckets) numBuckets = 1;
    
    Node *buckets = (Node*)calloc(numBuckets, sizeof(Node));
    
    int max = arr[0];
    for(int i = 0; i < size; i++) max = (max > arr[i]) ? max : arr[i];
    
    for(int i = 0; i < size; i++) {
        int idx = (arr[i] * numBuckets) / (max + 1);
        insertSorted(&buckets[idx], arr[i]);
    }
    
    for(int i = 0, arrIdx = 0; i < numBuckets; i++) {
        for(Node* trav = &buckets[i]; *trav != NULL; deleteFirst(trav)) {
            arr[arrIdx++] = (*trav)->data;
        }
    }
    
    free(buckets);
}