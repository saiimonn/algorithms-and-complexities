#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

typedef int Matrix[MAX][MAX];

int **warshall(Matrix);
void displayWarshall(int **);

void initMatrix(Matrix);
void insert(Matrix, int []);
void displayMatrix(Matrix);

int main() {
    
}

void initMatrix(Matrix M) {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            M[i][j] = 0;
        }
    }
}

void insert(Matrix M, int edge[2]) {
    M[edge[0]][edge[1]] = 1;
    M[edge[1]][edge[0]] = 1;
}

void displayMatrix(Matrix M) {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            printf("%3d", M[i][j]);
        }
        printf("\n");
    }
}

int **warshall(Matrix M) {
    int **warshall = (int**)malloc(sizeof(int*) * MAX);

    int i, j, k;
    for(i = 0; i < MAX; i++) {
        warshall[i] = (int*)malloc(sizeof(int) * MAX);
        memcpy(warshall[i], M[i], sizeof(int) * MAX);
    }

    for(i = 0; i < MAX; i++) {
        warshall[i][i] = 0;
    }

    for(k = 0; k < MAX; k++) {
        for(i = 0; i < MAX; i++) {
            for(j = 0; j < MAX; j++) {
                if (i != j) {
                    warshall[i][j] = warshall[i][j] || (warshall[i][k] && warshall[k][j]);
                }
            }
        }
    }
    return warshall;
}

void displayWarshall(int **warshall) {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            printf("%3d", warshall[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}