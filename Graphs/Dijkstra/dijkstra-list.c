#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#define INF 9999

typedef int Set[MAX];

typedef struct node {
    int data;
    int weight;
    struct node *link;
} *Vertex;

typedef Vertex List[MAX];

int *dijkstra(List, int);
void displayShortestPath(int [], int);

void initList(List);
void insertEdge(List, int []);
void display(List);

int main() {
    int edges[][3] = {
        {0, 1, 2},
        {0, 2, 4},
        {1, 2, 1},
        {1, 3, 7},
        {2, 4, 3},
        {4, 3, 2},
    };
    int size = sizeof(edges) / sizeof(edges[0]);

    List L;
    initList(L);

    for(int i = 0; i < size; i++) {
        insertEdge(L, edges[i]);
    }
    displayList(L);

    printf("\n");
    int root = 0;
    int *dj = dijkstra(L, root);
    displayShortestPath(dj, root);
}

void initList(List L) {
    for(int i = 0; i < MAX; i++) {
        L[i] = NULL;
    }
}

void insertEdge(List L, int edge[3]) {
    Vertex newNode = (Vertex)malloc(sizeof(struct node));

    if (newNode != NULL) {
        newNode->data = edge[1];
        newNode->weight = edge[2];
        newNode->link = L[edge[0]];
        L[edge[0]] = newNode;
    }
}

void displayList(List L) {
    for(int i = 0; i < MAX; i++) {
        printf("Node %d: ", i);
        for(Vertex trav = L[i]; trav != NULL; trav = trav->link) {
            printf("[%d] -> ", trav->data);
        }
        printf("NULL\n");
    }
}

int *dijkstra(List L, int root) {
    int *shortestPath = (int*)malloc(sizeof(int) * MAX);

    if (shortestPath != NULL) {
        Set visited = {0};
        visited[root] = 1;

        // 1: set shortestPaths to INF
        for(int i = 0; i < MAX; i++) {
            shortestPath[i] = INF;
        }

        // 2: set path from root to its adjacent vertices as their respective weights
        for(Vertex trav = L[root]; trav != NULL; trav = trav->link) {
            shortestPath[trav->data] = trav->weight;
        }

        shortestPath[root] = 0;

        for(int i = 1; i < MAX; i++) {
            int min = INF;
            int minNode;

            // 3: find unvisited nodes with the least amount of weights
            for(int j = 0; j < MAX; j++) {
                if(visited[j] == 0 && shortestPath[j] < min) {
                    min = shortestPath[j];
                    minNode = j;
                }
            }

            if (min != INF) {
                visited[minNode] = 1;

                for(int j = 0; j < MAX; j++) {
                    if (visited[j] == 0) {
                        Vertex trav;

                        // 4: find all nodes that are connected to minNode
                        for(trav = L[minNode]; trav != NULL && trav->data != j; trav = trav->link) {}

                        if (trav != NULL) {
                            // 5: compare and assign value for j
                            shortestPath[j] = (trav->weight + min < shortestPath[j]) ? trav->weight + min : shortestPath[j];
                        }
                    }
                }
            } else {
                printf("Graph not connected\n");
            }
        }
    }
    return shortestPath;
}

void displayShortestPath(int arr[], int root) {
    printf("\nDijkstra's Path from %d\n", root);

    for(int i = 0; i < MAX; i++) {
        printf("Path from %d to %d: ", root, i);
        (arr[i] == 0) ? printf("NONE\n") : printf("%d\n", arr[i]);
    }
}