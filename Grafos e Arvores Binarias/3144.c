#include <stdio.h>
#include <stdlib.h>

#define MAX 500

typedef struct {
    int u, v, w;
} Aresta;

int parent[MAX + 1], rank[MAX + 1];
Aresta arestas[124750];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int x, int y) {
    int raizX = find(x);
    int raizY = find(y);
    if (raizX != raizY) {
        if (rank[raizX] > rank[raizY])
            parent[raizY] = raizX;
        else if (rank[raizX] < rank[raizY])
            parent[raizX] = raizY;
        else {
            parent[raizY] = raizX;
            rank[raizX]++;
        }
    }
}

int compare(const void *a, const void *b) {
    return ((Aresta *)a)->w - ((Aresta *)b)->w;
}

int main() {
    int N, M, O;
    scanf("%d %d", &N, &M);
    scanf("%d", &O);
    
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &arestas[i].u, &arestas[i].v, &arestas[i].w);
    }
    
    qsort(arestas, M, sizeof(Aresta), compare);
    
    int mst = 0;
    for (int i = 0; i < M; i++) {
        if (find(arestas[i].u) != find(arestas[i].v)) {
            unite(arestas[i].u, arestas[i].v);
            mst += arestas[i].w;
        }
    }
    
    printf("%d\n", 2 * mst);
    return 0;
}
