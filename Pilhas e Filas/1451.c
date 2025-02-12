#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100000

typedef struct Node {
    char data;
    struct Node *next;
    struct Node *prev;
} Node;

Node *createNode(char data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAfter(Node **tail, Node **current, char data) {
    Node *newNode = createNode(data);
    if (*tail != NULL) {
        newNode->prev = *tail;
        (*tail)->next = newNode;
    }
    *tail = newNode;
    *current = newNode;
}

void insertBefore(Node **head, Node **current, char data) {
    Node *newNode = createNode(data);
    if (*head != NULL) {
        newNode->next = *head;
        (*head)->prev = newNode;
    }
    *head = newNode;
    *current = newNode;
}

void printList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        putchar(temp->data);
        temp = temp->next;
    }
    putchar('\n');
}

void freeList(Node *head) {
    Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    char input[MAX_LENGTH + 1];

    while (fgets(input, sizeof(input), stdin)) {
        if (input[0] == '\n') {
            continue;
        }

        Node *head = NULL, *tail = NULL, *current = NULL;

        current = head;

        for (int i = 0; input[i] != '\0' && input[i] != '\n'; i++) {
            if (input[i] == '[') {
                current = NULL;
            } else if (input[i] == ']') {
                current = tail;
            } else {
                if (current == NULL) {
                    insertBefore(&head, &current, input[i]);
                    if (tail == NULL) {
                        tail = current;
                    }
                } else {
                    Node *newNode = createNode(input[i]);
                    newNode->next = current->next;
                    if (current->next != NULL) {
                        current->next->prev = newNode;
                    }
                    current->next = newNode;
                    newNode->prev = current;
                    current = newNode;
                    if (current->next == NULL) {
                        tail = current;
                    }
                }
            }
        }

        printList(head);
        freeList(head);
    }

    return 0;
}
