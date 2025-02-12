#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *left, *right;
} Node;

Node* insert(Node* root, int value) {
    if (root == NULL) {
        Node* newNode = (Node*) malloc(sizeof(Node));
        newNode->value = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (value < root->value)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);
    return root;
}

void getPreorder(Node* root, int arr[], int *idx) {
    if (root == NULL)
        return;
    arr[(*idx)++] = root->value;
    getPreorder(root->left, arr, idx);
    getPreorder(root->right, arr, idx);
}

void getInorder(Node* root, int arr[], int *idx) {
    if (root == NULL)
        return;
    getInorder(root->left, arr, idx);
    arr[(*idx)++] = root->value;
    getInorder(root->right, arr, idx);
}

void getPostorder(Node* root, int arr[], int *idx) {
    if (root == NULL)
        return;
    getPostorder(root->left, arr, idx);
    getPostorder(root->right, arr, idx);
    arr[(*idx)++] = root->value;
}

void freeTree(Node* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    int C, N;
    scanf("%d", &C);
    
    for (int caseNum = 1; caseNum <= C; caseNum++) {
        scanf("%d", &N);
        Node* root = NULL;
        for (int i = 0; i < N; i++) {
            int value;
            scanf("%d", &value);
            root = insert(root, value);
        }
        
        int pre[600], in[600], post[600];
        int idxPre = 0, idxIn = 0, idxPost = 0;
        
        getPreorder(root, pre, &idxPre);
        getInorder(root, in, &idxIn);
        getPostorder(root, post, &idxPost);
        
        printf("Case %d:\n", caseNum);
        
        printf("Pre.: ");
        for (int i = 0; i < idxPre; i++) {
            printf("%d", pre[i]);
            if (i < idxPre - 1)
                printf(" ");
        }
        printf("\n");
        
        printf("In..: ");
        for (int i = 0; i < idxIn; i++) {
            printf("%d", in[i]);
            if (i < idxIn - 1)
                printf(" ");
        }
        printf("\n");
        
        printf("Post: ");
        for (int i = 0; i < idxPost; i++) {
            printf("%d", post[i]);
            if (i < idxPost - 1)
                printf(" ");
        }
        printf("\n\n");
        
        freeTree(root);
    }
    
    return 0;
}
