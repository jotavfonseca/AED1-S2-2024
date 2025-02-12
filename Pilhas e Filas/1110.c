#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void freeList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n;
    while (scanf("%d", &n) && n != 0) {
        if (n == 1) {
            printf("Discarded cards:\n");
            printf("Remaining card: 1\n");
            continue;
        }

        Node* head = createNode(1);
        Node* tail = head;
        for (int i = 2; i <= n; i++) {
            tail->next = createNode(i);
            tail = tail->next;
        }
        tail->next = head;

        printf("Discarded cards: ");
        while (head != head->next) {
            printf("%d", head->value);
            Node* temp = head;
            head = head->next;
            free(temp);

            tail->next = head;
            tail = tail->next;

            if (head != head->next) {
                printf(", ");
                head = head->next;
            }
        }

        printf("\nRemaining card: %d\n", head->value);
        free(head);
    }

    return 0;
}
