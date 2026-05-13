#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5
#define INF 9999

typedef int Set[MAX];

typedef int Matrix[MAX][MAX];

int *dijkstra(Matrix, int);
void displayShortestPath(int [], int);

void initMatrix(Matrix);
void insert(Matrix, int[]);
void displayMatrix(Matrix);

int main() {
    
}

void initMatrix(Matrix M) {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            M[i][j] = INF;
        }
    }
}

void insert(Matrix M, int edge[3]) {
    M[edge[0]][edge[1]] = edge[2];
}

void displayMatrix(Matrix M) {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            (M[i][j] == INF) ? printf("INF ") : printf("%3d ", M[i][j]);
        }
        printf("\n");
    }
}