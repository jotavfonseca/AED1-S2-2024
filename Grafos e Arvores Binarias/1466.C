#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}

void bfs(Node* root) {
    if (root == NULL) {
        return;
    }
    
    Node* queue[500];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        Node* current = queue[front++];

        if (front > 1) {
            printf(" ");
        }
        printf("%d", current->value);

        if (current->left != NULL) {
            queue[rear++] = current->left;
        }
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
}

int main() {
    int C;
    scanf("%d", &C);
    
    for (int t = 1; t <= C; t++) {
        int N;
        scanf("%d", &N);

        Node* root = NULL;

        for (int i = 0; i < N; i++) {
            int value;
            scanf("%d", &value);
            root = insert(root, value);
        }

        printf("Case %d:\n", t);
        bfs(root);
        printf("\n\n");
    }

    return 0;
}
