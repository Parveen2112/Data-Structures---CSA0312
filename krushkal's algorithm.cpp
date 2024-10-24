#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int u, v, w;
} Edge;
int find(int parent[], int i) {
    if (parent[i] == -1) return i;
    return find(parent, parent[i]);
}
void unionSet(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}
int compare(const void *a, const void *b) {
    return ((Edge *)a)->w - ((Edge *)b)->w;
}
void kruskal(Edge edges[], int V, int E) {
    qsort(edges, E, sizeof(edges[0]), compare);
    int parent[V];
    for (int i = 0; i < V; i++) parent[i] = -1;
    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (find(parent, u) != find(parent, v)) {
            printf("%d -- %d == %d\n", u, v, edges[i].w);
            unionSet(parent, u, v);
        }
    }
}
int main() {
    int V = 4; // Number of vertices
    Edge edges[] = { {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4} };
    int E = sizeof(edges) / sizeof(edges[0]);
    kruskal(edges, V, E);
    return 0;
}
