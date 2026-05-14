#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX 10

typedef int Edge[2]; 
// Edge[0] = weight/dist
// Edge[1] = vertex

typedef struct node {
    Edge data;
    struct node* next;
} Node, *List;

typedef List AdjacencyList[MAX];

typedef struct {
    Edge arr[MAX];
    int size;
} PrioQueue;


/* ================= PRIORITY QUEUE ================= */

void heapifySubtreeR(PrioQueue* queue, int root){
    int left = root * 2 + 1;
    int right = left + 1;
    int smallest = root;

    if(left < queue->size &&
       queue->arr[left][0] < queue->arr[smallest][0]){
        smallest = left;
    }

    if(right < queue->size &&
       queue->arr[right][0] < queue->arr[smallest][0]){
        smallest = right;
    }

    if(smallest != root){
        Edge temp;

        memcpy(temp, queue->arr[smallest], sizeof(Edge));
        memcpy(queue->arr[smallest], queue->arr[root], sizeof(Edge));
        memcpy(queue->arr[root], temp, sizeof(Edge));

        heapifySubtreeR(queue, smallest);
    }
}

Edge* dequeue(PrioQueue* queue){
    if(queue->size == 0){
        return NULL;
    }

    static Edge result;

    memcpy(result, queue->arr[0], sizeof(Edge));
    memcpy(queue->arr[0],
           queue->arr[queue->size - 1],
           sizeof(Edge));

    queue->size--;

    heapifySubtreeR(queue, 0);

    return &result;
}

void insertMin(PrioQueue* queue, Edge elem){
    if(queue->size >= MAX){
        return;
    }

    int insertPos = queue->size++;
    int parent = (insertPos - 1) / 2;

    while(insertPos > 0 &&
          elem[0] < queue->arr[parent][0]){

        memcpy(queue->arr[insertPos],
               queue->arr[parent],
               sizeof(Edge));

        insertPos = parent;
        parent = (parent - 1) / 2;
    }

    memcpy(queue->arr[insertPos], elem, sizeof(Edge));
}


/* ================= GRAPH ================= */

void insertEdge(AdjacencyList list, int src, int weight, int dest){
    Node* temp = (Node*)malloc(sizeof(Node));

    temp->data[0] = weight;
    temp->data[1] = dest;
    temp->next = list[src];

    list[src] = temp;
}

void displayGraph(AdjacencyList list){
    for(int i = 0; i < MAX; i++){
        printf("%d -> ", i);

        for(List trav = list[i];
            trav != NULL;
            trav = trav->next){

            printf("(%d,%d) ",
                   trav->data[1],
                   trav->data[0]);
        }

        printf("\n");
    }
}


/* ================= DIJKSTRA ================= */

int* dijkstra(AdjacencyList list, Edge start){
    PrioQueue q = {.size = 0};

    int* d = (int*)malloc(sizeof(int) * MAX);

    for(int j = 0; j < MAX; j++){
        d[j] = INT_MAX;
    }

    d[start[1]] = 0;

    insertMin(&q, start);

    while(q.size != 0){

        Edge* p = dequeue(&q);

        if(p == NULL){
            break;
        }

        // Ignore outdated entries
        if((*p)[0] != d[(*p)[1]]){
            continue;
        }

        for(List i = list[(*p)[1]];
            i != NULL;
            i = i->next){

            Edge uv;

            memcpy(uv, i->data, sizeof(Edge));

            if(d[(*p)[1]] + uv[0] < d[uv[1]]){

                d[uv[1]] = d[(*p)[1]] + uv[0];

                Edge new_edge = {
                    d[uv[1]],
                    uv[1]
                };

                insertMin(&q, new_edge);
            }
        }
    }

    return d;
}


/* ================= MAIN ================= */

int main(){

    AdjacencyList graph = {NULL};

    insertEdge(graph, 0, 4, 1);
    insertEdge(graph, 0, 1, 2);

    insertEdge(graph, 2, 2, 1);
    insertEdge(graph, 2, 5, 3);

    insertEdge(graph, 1, 1, 3);

    insertEdge(graph, 3, 3, 4);

    displayGraph(graph);

    Edge start = {0, 0};

    int* dist = dijkstra(graph, start);

    printf("\nShortest distances from vertex 0:\n");

    for(int i = 0; i < MAX; i++){

        if(dist[i] == INT_MAX){
            printf("%d : INF\n", i);
        } else {
            printf("%d : %d\n", i, dist[i]);
        }
    }

    free(dist);

    return 0;
}