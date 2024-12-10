#include <stdio.h>

typedef struct Node
{
    char data[21];
    struct Node* next;  
} Node;

Node* createNode(char* data) { 
    Node* newNode = (Node*)malloc(sizeof(Node)); 
    strcpy(newNode->data, data);
    newNode->next = NULL;  
    return newNode;
}

void insert(Node** head, const char* data) {
    Node* newNode = createNode(data);
    if (*head == NULL || strcmp((*head)->data, data) > 0) {
        newNode->next = *head;
        *head = newNode;
    } else if (strcmp((*head)->data, data) == 0) {
        free(newNode); // Duplicata encontrada
    } else {
        Node* current = *head;
        while (current->next != NULL && strcmp(current->next->data, data) < 0) {
            current = current->next;
        }
        if (current->next != NULL && strcmp(current->next->data, data) == 0) {
            free(newNode); // Duplicata encontrada
        } else {
            newNode->next = current->next;
            current->next = newNode;
        }
    }
}

void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%s ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}



int main() {
    int N;
    char buffer[10001]; 

    // printf("Insira o número de listas de compras:\n");
    scanf("%d", &N);
    getchar(); // Consumir o newline após o número

    for (int i = 0; i < N; i++) {
        Node* head = NULL;
        // printf("Insira a lista de compras %d:\n", i + 1);
        fgets(buffer, sizeof(buffer), stdin);

        char* token = strtok(buffer, " \n");
        while (token != NULL) {
            insert(&head, token);
            token = strtok(NULL, " \n");
        }

        // printf("Lista de compras %d organizada:\n", i + 1);
        displayList(head);

        Node* temp;
        while (head != NULL) {
            temp = head;
            head = head->next;
            free(temp);
        }
    }

    return 0;
}
