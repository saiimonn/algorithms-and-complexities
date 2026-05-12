#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct node {
    int data;
    struct node *link;
} *Vertex;

typedef Vertex List[MAX];
typedef int Set[MAX];

void dfs(List, Set, int);
void init(List);
void insert(List, int[]);
void displayList(List);

int main() {
    int edges[][2] = { //depends on the arrangement of the nodes in the list
        {4, 6},
        {4, 5},
        {5, 1},
        {6, 5},
        {6, 3},
        {1, 3},
        {3, 0},
        {3, 2},
        {1, 2},
        {0, 1},
        {2, 0},
        {0, 2},
    }; //prints 4 5 1 2 0 3 6
    int size = sizeof(edges) / sizeof(edges[0]);
    
    List L;
    init(L);
    Set S = {0};
    
    for(int i = 0; i < size; i++) {
        insert(L, edges[i]);
    }
    displayList(L);
    
    printf("\nDFS: ");
    dfs(L, S, 4);
}

void init(List L) {
    for(int i = 0; i < MAX; i++) {
        L[i] = NULL;
    }
}

void insert(List L, int edge[2]) {
    Vertex newNode = (Vertex)malloc(sizeof(struct node));

    if (newNode != NULL) {
        newNode->data = edge[1];
        newNode->link = L[edge[0]];
        L[edge[0]] = newNode;
    }
}

void displayList(List L) {
    for(int i = 0; i < MAX; i++) {
        printf("Node %d: ", i);
        for(Vertex trav = L[i]; trav != NULL; trav = trav->link) {
            printf("%3d -> ", trav->data);
        }
        printf("\n");
    }
}

void dfs(List L, Set visited, int src) {
    visited[src] = 1;
    printf("%d ", src);

    for(Vertex trav = L[src]; trav != NULL; trav = trav->link) {
        if (visited[trav->data] == 0) {
            dfs(L, visited, trav->data);
        }
    }
}