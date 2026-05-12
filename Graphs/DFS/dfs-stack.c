#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    int arr[MAX];
    int top;
} Stack;

typedef int Matrix[MAX][MAX];
typedef int Set[MAX];

void initStack(Stack *);
bool isFull(Stack);
bool isEmpty(Stack);
void push(Stack *, int);
int pop(Stack *);

void initMatrix(Matrix);
void insertEdge(Matrix, int[]);
void displayMatrix(Matrix);

void dfs(Matrix, int);

int main() { 
    int edges[][2] = {
        {4, 5},
        {4, 6},
        {5, 1},
        {6, 5},
        {6, 3},
        {1, 3},
        {1, 2},
        {3, 0},
        {3, 2},
        {0, 2},
        {0, 1},
    };
    int size = sizeof(edges) / sizeof(edges[0]);

    Matrix M;
    initMatrix(M);

    for(int i = 0; i < size; i++) {
        insertEdge(M, edges[i]);
    }

    displayMatrix(M);
    printf("\nDFS: ");

    dfs(M, 1);
}

void initStack(Stack *S) {
    S->top = -1;
}

bool isFull(Stack S) {
    return S.top + 1 == MAX;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

void push(Stack *S, int data) {
    if(!isFull(*S)) {
        S->arr[++S->top] = data;
    }
}

int pop(Stack *S) {
    int retval = -1;
    if(!isEmpty(*S)) {
        retval = S->arr[S->top];
        S->top--;
    }
    return retval;
}

void initMatrix(Matrix M) {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++){ 
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

void dfs(Matrix M, int src) {
    Set visited = {0};
    Stack S;
    initStack(&S);

    push(&S, src);

    while (!isEmpty(S)) {
        int node = pop(&S);
        if (visited[node]) continue;
        visited[node] = 1;
        printf("%d ", node);

        for(int i = 0; i < MAX; i++) {
            if (visited[i] == 0 && M[node][i] != 0) {
                push(&S, i);
            }
        }
    }
}