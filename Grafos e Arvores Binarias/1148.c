#include <stdio.h>
#include <stdlib.h>

#define MAXN 500
#define INF 1000000000

int dist[MAXN + 1][MAXN + 1];

void floyd_warshall(int N) {
    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (dist[i][k] < INF && dist[k][j] < INF)
                    if (dist[i][j] > dist[i][k] + dist[k][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
    
    // Conectar cidades no mesmo país (caminho bidirecional)
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (dist[i][j] != INF && dist[j][i] != INF)
                dist[i][j] = dist[j][i] = (dist[i][j] < dist[j][i]) ? dist[i][j] : dist[j][i];
}

int main() {
    int N, E;
    while (scanf("%d %d", &N, &E) && (N || E)) {
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                dist[i][j] = (i == j) ? 0 : INF;
        
        for (int i = 0; i < E; i++) {
            int X, Y, H;
            scanf("%d %d %d", &X, &Y, &H);
            if (dist[Y][X] != INF) {
                dist[X][Y] = dist[Y][X] = 0;
            } else {
                dist[X][Y] = H;
            }
        }
        
        floyd_warshall(N);
        
        int K;
        scanf("%d", &K);
        while (K--) {
            int O, D;
            scanf("%d %d", &O, &D);
            if (dist[O][D] == INF)
                printf("Nao e possivel entregar a carta\n");
            else
                printf("%d\n", dist[O][D]);
        }
        printf("\n");
    }
    return 0;
}