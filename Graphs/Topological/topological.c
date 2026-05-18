#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct node {
    int vertex;
    struct node *link;
} Node, *List;

typedef List AdjacencyList[MAX];

typedef struct {
    int arr[MAX];
    int front, rear;
} Queue;

void initQueue(Queue *Q) {
    Q->front = 1;
    Q->rear = 0;
}