#include <stdio.h>
#include <stdlib.h>

#define MAX 40000

typedef struct {
    int u, v, w;
} Aresta;

int parent[MAX], rank[MAX];
Aresta arestas[MAX];

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
    int m, n;
    while (scanf("%d %d", &m, &n) && (m || n)) {
        int total = 0, mst = 0;
        for (int i = 0; i < m; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &arestas[i].u, &arestas[i].v, &arestas[i].w);
            total += arestas[i].w;
        }
        qsort(arestas, n, sizeof(Aresta), compare);
        for (int i = 0; i < n; i++) {
            if (find(arestas[i].u) != find(arestas[i].v)) {
                unite(arestas[i].u, arestas[i].v);
                mst += arestas[i].w;
            }
        }
        printf("%d\n", mst);
    }
    return 0;
}
