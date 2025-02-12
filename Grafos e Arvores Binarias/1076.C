#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 50 

int adjacency_list[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int moves;

void dfs(int node) {
    for (int i = 0; i < MAX_NODES; i++) {
        if (adjacency_list[node][i] && !visited[i]) {
            visited[i] = 1;
            moves += 2; 
            dfs(i);
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        int start, V, A;
        scanf("%d", &start);
        scanf("%d %d", &V, &A);

        memset(adjacency_list, 0, sizeof(adjacency_list));
        memset(visited, 0, sizeof(visited));
        moves = 0;

        for (int i = 0; i < A; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            adjacency_list[u][v] = 1;
            adjacency_list[v][u] = 1; // Grafo não direcionado
        }

        visited[start] = 1;
        dfs(start);

        printf("%d\n", moves);
    }

    return 0;
}
