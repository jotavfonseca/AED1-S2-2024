#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 10000
#define MAX_M 30000

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* adj[MAX_N + 1];
int visited[MAX_N + 1];
int in_stack[MAX_N + 1];

void add_edge(int u, int v) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = v;
    new_node->next = adj[u];
    adj[u] = new_node;
}

int dfs(int node) {
    visited[node] = 1;
    in_stack[node] = 1;
    
    Node* curr = adj[node];
    while (curr) {
        int next = curr->value;
        if (!visited[next]) {
            if (dfs(next))
                return 1;
        } else if (in_stack[next]) {
            return 1;
        }
        curr = curr->next;
    }
    
    in_stack[node] = 0;
    return 0;
}

int has_cycle(int n) {
    memset(visited, 0, sizeof(visited));
    memset(in_stack, 0, sizeof(in_stack));

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dfs(i))
            return 1;
    }
    return 0;
}

void clear_graph(int n) {
    for (int i = 1; i <= n; i++) {
        Node* curr = adj[i];
        while (curr) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
        adj[i] = NULL;
    }
}

int main() {
    int T, N, M, A, B;
    scanf("%d", &T);
    
    while (T--) {
        scanf("%d %d", &N, &M);
        
        for (int i = 1; i <= N; i++)
            adj[i] = NULL;

        for (int i = 0; i < M; i++) {
            scanf("%d %d", &A, &B);
            add_edge(A, B);
        }

        printf("%s\n", has_cycle(N) ? "SIM" : "NAO");
        
        clear_graph(N);
    }
    
    return 0;
}
