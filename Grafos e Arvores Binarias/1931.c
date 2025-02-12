#include <stdio.h>
#include <stdlib.h>
#define INF 1000000000

typedef struct Edge {
    int v, w;
    struct Edge *next;
} Edge;

Edge *adj[10005];
typedef struct {
    int cost, node, par;
} State;

State heap[210000];
int heap_size = 0;

void swap(State *a, State *b) {
    State t = *a; *a = *b; *b = t;
}

void push(State s) {
    heap[++heap_size] = s;
    int i = heap_size;
    while(i > 1 && heap[i].cost < heap[i/2].cost) {
        swap(&heap[i], &heap[i/2]);
        i /= 2;
    }
}

State pop() {
    State ret = heap[1];
    heap[1] = heap[heap_size--];
    int i = 1;
    while(1) {
        int l = i * 2, r = i * 2 + 1, smallest = i;
        if(l <= heap_size && heap[l].cost < heap[smallest].cost) smallest = l;
        if(r <= heap_size && heap[r].cost < heap[smallest].cost) smallest = r;
        if(smallest == i) break;
        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
    return ret;
}

void add_edge(int u, int v, int w) {
    Edge *e = (Edge*)malloc(sizeof(Edge));
    e->v = v; e->w = w; e->next = adj[u];
    adj[u] = e;
}

void free_graph(int n) {
    for(int i = 1; i <= n; i++) {
        Edge *e = adj[i];
        while(e) {
            Edge *tmp = e;
            e = e->next;
            free(tmp);
        }
        adj[i] = 0;
    }
}

int dist[10005][2];
int main(){
    int C, V;
    scanf("%d %d", &C, &V);
    for(int i = 1; i <= C; i++) adj[i] = 0;
    for(int i = 0; i < V; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    for(int i = 1; i <= C; i++){
        dist[i][0] = dist[i][1] = INF;
    }
    dist[1][0] = 0;
    heap_size = 0;
    push((State){0,1,0});
    while(heap_size){
        State s = pop();
        if(s.cost != dist[s.node][s.par]) continue;
        for(Edge *e = adj[s.node]; e; e = e->next){
            int np = s.par ^ 1;
            int nc = s.cost + e->w;
            if(nc < dist[e->v][np]){
                dist[e->v][np] = nc;
                push((State){nc, e->v, np});
            }
        }
    }
    int ans = dist[C][0];
    if(ans == INF) ans = -1;
    printf("%d\n", ans);
    free_graph(C);
    return 0;
}
