#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 10
#define INF INT_MAX

typedef struct {
    int src, dest, weight;
} Edge;

typedef struct {
    Edge edges[MAX];
    int V, E;
} Graph;

void addEdge(Graph *g, int src, int dest, int weight) {
    g->edges[g->E].src = src;
    g->edges[g->E].dest = dest;
    g->edges[g->E].weight = weight;
    g->E++;
}

int bellmanFord(Graph *G, int start, int dist[]) {
    for(int i = 0; i < G->V; i++) {
        dist[i] = INF;
    }   

    dist[start] = 0;

    for(int i = 1; i <= G->V - 1; i++) { 
        for(int j = 0; j < G->E; j++) {
            int u = G->edges[j].src;
            int v = G->edges[j].dest;
            int w = G->edges[j].weight;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for(int j = 0; j < G->E; j++) {
        int u = G->edges[j].src;
        int v = G->edges[j].dest;
        int w = G->edges[j].weight;

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            return 0;
        }
    }

    return 1;
}

int main(){

    Graph g;
    g.V = 5;
    g.E = 0;

    addEdge(&g, 0, 1, -1);
    addEdge(&g, 0, 2, 4);
    addEdge(&g, 1, 2, 3);
    addEdge(&g, 1, 3, 2);
    addEdge(&g, 1, 4, 2);
    addEdge(&g, 3, 2, 5);
    addEdge(&g, 3, 1, 1);
    addEdge(&g, 4, 3, -3);

    int dist[MAX];

    if(bellmanFord(&g, 0, dist)){
        printf("Shortest distances from source 0:\n");
        for(int i = 0; i < g.V; i++){
            if(dist[i] == INF)
                printf("%d : INF\n", i);
            else
                printf("%d : %d\n", i, dist[i]);
        }
    } else {
        printf("Graph contains a negative weight cycle!\n");
    }

    return 0;
}