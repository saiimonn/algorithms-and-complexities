#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5
#define INF 9999

typedef int Matrix[MAX][MAX];

int **floyds(Matrix);
void displayFloyds(int **);

void initMatrix(Matrix);
void insert(Matrix, int []);
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
    M[edge[1]][edge[0]] = edge[2];
}

void displayMatrix(Matrix M) {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            (M[i][j] == INF) ? printf("INF ") : printf("%3d", M[i][j]);
        }
        printf("\n");
    }
}

int **floyds(Matrix M) {
    int **floyds = (int**)malloc(sizeof(int*) * MAX);

    int i, j, k;
    for(i = 0; i < MAX; i++) {
        floyds[i] = (int*)malloc(sizeof(int) * MAX);
        memcpy(floyds[i], M[i], sizeof(int) * MAX);
    }

    for(i = 0; i < MAX; i++) {
        floyds[i][i] = 0;
    }

    for(k = 0; k < MAX; k++){ 
        for(i = 0; i < MAX; i++) {
            for(j = 0; j < MAX; j++) {
                int wgt = floyds[i][k] + floyds[k][j];
                floyds[i][j] = (wgt < floyds[i][j]) ? wgt : floyds[i][j];
            }
        }
    }
    return floyds;
}

void displayFloyds(int **floyd) {
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            (floyd[i][j] == INF) ? printf("INF ") : printf("%3d", floyd[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}