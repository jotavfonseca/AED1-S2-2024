#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

#define MAXN 1001
#define INF -1.0

typedef struct { int v; double p; } Aresta;
Aresta adj[MAXN][MAXN];
int grau[MAXN], atiradores[MAXN];
double prob[MAXN];

void dijkstra(int origem, int destino, int N, double P, int K) {
    for (int i = 1; i <= N; i++) prob[i] = INF;
    prob[origem] = (K >= atiradores[origem]) ? pow(P, atiradores[origem]) : 0.0;
    int visitado[MAXN] = {0};
    
    for (int i = 1; i <= N; i++) {
        int u = -1;
        for (int j = 1; j <= N; j++)
            if (!visitado[j] && (u == -1 || prob[j] > prob[u])) u = j;
        
        if (prob[u] == INF || prob[u] == 0.0) break;
        visitado[u] = 1;
        for (int j = 0; j < grau[u]; j++) {
            int v = adj[u][j].v;
            if (K >= atiradores[v]) {
                double nova_prob = prob[u] * pow(P, atiradores[v]);
                if (nova_prob > prob[v]) prob[v] = nova_prob;
            }
        }
    }
    if (prob[destino] == INF) printf("0.000\n");
    else printf("%.3lf\n", prob[destino]);
}

int main() {
    int N, M, K; double P;
    while (scanf("%d %d %d %lf", &N, &M, &K, &P) != EOF) {
        for (int i = 1; i <= N; i++) {
            grau[i] = 0;
            atiradores[i] = 0;
        }
        for (int i = 0; i < M; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adj[u][grau[u]++] = (Aresta){v, 1.0};
            adj[v][grau[v]++] = (Aresta){u, 1.0};
        }
        int A; scanf("%d", &A);
        for (int i = 0; i < A; i++) {
            int x; scanf("%d", &x);
            atiradores[x]++;
        }
        int origem, destino;
        scanf("%d %d", &origem, &destino);
        dijkstra(origem, destino, N, P, K);
    }
    return 0;
}
