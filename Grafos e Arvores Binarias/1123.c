#include <stdio.h>
#include <limits.h>

#define MAXN 250
#define INF INT_MAX

typedef struct {
    int cidade, custo;
} No;

int N, M, C, K;
int adj[MAXN][MAXN];
int dist[MAXN];
int visitado[MAXN];

void dijkstra(int origem) {
    for (int i = 0; i < N; i++) {
        dist[i] = INF;
        visitado[i] = 0;
    }
    dist[origem] = 0;

    for (int i = 0; i < N; i++) {
        int u = -1, menor = INF;
        for (int j = 0; j < N; j++) {
            if (!visitado[j] && dist[j] < menor) {
                menor = dist[j];
                u = j;
            }
        }

        if (u == -1) break;
        visitado[u] = 1;

        for (int v = 0; v < N; v++) {
            if (adj[u][v] != INF && dist[v] > dist[u] + adj[u][v]) {
                if (u >= C || (u < C - 1 && v == u + 1)) {
                    dist[v] = dist[u] + adj[u][v];
                }
            }
        }
    }
}

int main() {
    while (1) {
        scanf("%d %d %d %d", &N, &M, &C, &K);
        if (N == 0 && M == 0 && C == 0 && K == 0) break;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                adj[i][j] = INF;
            }
        }

        for (int i = 0; i < M; i++) {
            int U, V, P;
            scanf("%d %d %d", &U, &V, &P);
            adj[U][V] = P;
            adj[V][U] = P;
        }

        dijkstra(K);
        printf("%d\n", dist[C - 1]);
    }
    return 0;
}
