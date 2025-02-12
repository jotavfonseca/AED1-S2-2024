#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NODES 250
#define MAX_EDGES 5000
#define INF 1000000000

int head[MAX_NODES], nxt[MAX_EDGES], to[MAX_EDGES], cap[MAX_EDGES], edgeCount;
int level[MAX_NODES], Q[MAX_NODES], work[MAX_NODES];
int source, sink, nNodes;

void addEdge(int u, int v, int c) {
    nxt[edgeCount] = head[u];
    to[edgeCount] = v;
    cap[edgeCount] = c;
    head[u] = edgeCount++;
    nxt[edgeCount] = head[v];
    to[edgeCount] = u;
    cap[edgeCount] = 0;
    head[v] = edgeCount++;
}

int bfs() {
    int front = 0, rear = 0;
    memset(level, -1, sizeof(level));
    level[source] = 0;
    Q[rear++] = source;
    while (front < rear) {
        int u = Q[front++];
        for (int i = head[u]; i != -1; i = nxt[i]) {
            int v = to[i];
            if (level[v] < 0 && cap[i] > 0) {
                level[v] = level[u] + 1;
                Q[rear++] = v;
            }
        }
    }
    return level[sink] >= 0;
}

int dfs(int u, int flow) {
    if (u == sink)
        return flow;
    for (int *i = &work[u]; *i != -1; ) {
        int v = to[*i];
        if (level[v] == level[u] + 1 && cap[*i] > 0) {
            int pushed = dfs(v, flow < cap[*i] ? flow : cap[*i]);
            if (pushed) {
                cap[*i] -= pushed;
                cap[*i ^ 1] += pushed;
                return pushed;
            }
        }
        *i = nxt[*i];
    }
    return 0;
}

int dinic() {
    int flow = 0;
    while (bfs()) {
        memcpy(work, head, sizeof(head));
        while (1) {
            int pushed = dfs(source, INF);
            if (!pushed)
                break;
            flow += pushed;
        }
    }
    return flow;
}

int main() {
    int n, m, k, i;
    int horseCap[110];
    int u, v;
    int inst = 1;
    while (scanf("%d %d %d", &n, &m, &k) != EOF) {
        nNodes = n + m + 2;
        source = 0;
        sink = n + m + 1;
        for (i = 0; i < nNodes; i++)
            head[i] = -1;
        edgeCount = 0;
        for (i = 0; i < n; i++)
            scanf("%d", &horseCap[i]);
        for (i = 1; i <= n; i++)
            addEdge(source, i, horseCap[i - 1]);
        for (i = 0; i < k; i++) {
            scanf("%d %d", &u, &v);
            addEdge(u, n + v, 1);
        }
        for (i = 1; i <= m; i++)
            addEdge(n + i, sink, 1);
        int maxFlow = dinic();
        printf("Instancia %d\n%d\n\n", inst++, maxFlow);
    }
    return 0;
}
