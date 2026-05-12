#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 5

typedef int Set[MAX];

typedef struct node {
    int data;
    struct node *link;
} *Vertex;

typedef Vertex List[MAX];

typedef struct {
    int nodes[MAX];
    int front;
    int rear;
} Queue;

void bfs(List, int);
void initQueue(Queue *);
bool isEmpty(Queue);
void enqueue(Queue *, int);
int dequeue(Queue *);

void initList(List);
void insertEdge(List, int[]);
void displayList(List);
void displayEdges(List);

int main() {
    
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
    int retVal = -1;
    if (!isEmpty(*Q)) {
        retVal = Q->nodes[Q->front];
        Q->front = (Q->front + 1) % MAX;
    }
    return retVal;
}

void initList(List L) {
    for(int i = 0; i < MAX; i++) {
        L[i] = NULL;
    }
}

void insertEdge(List L, int edge[2]) {
    Vertex newNode = (Vertex)malloc(sizeof(struct node));

    if (newNode != NULL) {
        newNode->data = edge[1];
        newNode->link = L[edge[0]];
        L[edge[0]] = newNode;
    }

    newNode = (Vertex)malloc(sizeof(struct node));

    if (newNode != NULL) {
        newNode->data = edge[0];
        newNode->link = L[edge[1]];
        L[edge[1]] = newNode;
    }
}

void displayList(List L) {
    for(int i = 0; i < MAX; i++) {
        printf("Node %d: ", i);
        for(Vertex trav = L[i]; trav != NULL; trav = trav->link) {
            printf("%d -> ", trav->data);
        }
        printf("NULL\n");
    }
}

void bfs(List L, int src) {
    Set visited = {};
    visited[src] = 1;

    Queue Q;
    initQueue(&Q);
    enqueue(&Q, src);

    printf("BFS: ");
    while(!isEmpty(Q)) {
        int node = dequeue(&Q);
        printf("%d ", node);

        for(Vertex trav = L[node]; trav != NULL; trav = trav->link) {
            if (visited[trav->data] == 0) {
                visited[trav->data] = 1;
                enqueue(&Q, trav->data);
            }
        }
    }
}