#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5

typedef int Set[MAX];

typedef struct {
    int nodes[MAX];
    int front;
    int rear;
} Queue;

typedef int Matrix[MAX][MAX];

void bfs(Matrix, int);
void initQueue(Queue *);
bool isEmpty(Queue);
void enqueue(Queue *, int);
int dequeue(Queue *);

void initMatrix(Matrix);
void insertEdge(Matrix, int[]);
void displayMatrix(Matrix);
void displayEdge(Matrix);

int main() {
    Matrix M;

    initMatrix(M);

    insertEdge(M, (int[]){0,1});
    insertEdge(M, (int[]){0,2});
    insertEdge(M, (int[]){1,3});
    insertEdge(M, (int[]){2,4});
    insertEdge(M, (int[]){3,4});

    displayMatrix(M);
    printf("\n");

    displayEdge(M);
    printf("\n\n");

    bfs(M, 0);

    return 0;
}

void initQueue(Queue *Q) {
    Q->front = 1;
    Q->rear = 0;
}

bool isEmpty(Queue Q) {
    return (Q.rear + 1) % MAX == Q.front;
}

void enqueue(Queue *Q, int data) {
    if ((Q->rear + 2) % MAX != Q->front) {
        Q->rear = (Q->rear + 1) % MAX;
        Q->nodes[Q->rear] = data;
    }
}

int dequeue(Queue *Q) {
    int retval = -1;
    if (!isEmpty(*Q)) {
        retval = Q->nodes[Q->front];
        Q->front = (Q->front + 1) % MAX;
    }
    return retval;
}

void initMatrix(Matrix M) {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            M[i][j] = 0;
        }
    }
}

void insertEdge(Matrix M, int edge[2]) {
    M[edge[0]][edge[1]] = 1;
}

void displayMatrix(Matrix M) {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            printf("%3d", M[i][j]);
        }
        printf("\n");
    }
}

void displayEdge(Matrix M) {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            if(M[i][j] == 1) printf("(%d %d)\t", i, j);
        }
    }
}

void bfs(Matrix M, int src) {
    Set visited = {};
    Queue Q;
    initQueue(&Q);

    visited[src] = 1;
    enqueue(&Q, src);

    printf("BFS: ");
    while (!isEmpty(Q)) {
        int node = dequeue(&Q);
        printf("%d ", node);

        for(int i = 0; i < MAX; i++) {
            if (visited[i] == 0 && M[node][i] != 0) {
                visited[i] = 1;
                enqueue(&Q, i);
            }
        }
    }
}