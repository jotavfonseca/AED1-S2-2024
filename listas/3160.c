#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Amigo {
    char nome[100]; 
    struct Amigo *next;
} Amigo;

Amigo* create(char* valor) {
    Amigo *novo = (Amigo *)malloc(sizeof(Amigo));
    strcpy(novo->nome, valor);
    novo->next = NULL;
    return novo;
}

void insertAtEnd(Amigo** head, char* valor) {
    Amigo* novo = create(valor);
    if (*head == NULL) {
        *head = novo;
        return;
    }
    Amigo* aux = *head;
    while (aux->next != NULL) { 
        aux = aux->next; 
    } 
    aux->next = novo;
}

void insertBefore(Amigo** head, char* specificFriend, char* valor) {
    Amigo* novo = create(valor);
    if (*head == NULL) { 
        free(novo); 
        return;
    }
    if (strcmp((*head)->nome, specificFriend) == 0) {
        novo->next = *head;
        *head = novo;
        return;
    }
    Amigo* aux = *head;
    while (aux->next != NULL && strcmp(aux->next->nome, specificFriend) != 0) { 
        aux = aux->next; 
    } 
    if (aux->next == NULL) {
        free(novo); 
        return;
    }
    novo->next = aux->next;
    aux->next = novo;
}

void printList(Amigo* head) { 
    Amigo* aux = head; 
    while (aux != NULL) { 
        printf("%s -> ", aux->nome); 
        aux = aux->next; 
    }
    printf("NULL\n");
}

int main() {
    Amigo* head = NULL;
    char input[1000];
    char newInput[1000];
    char friendInput[100];

    printf("Digite a lista de amigos de Luiggy: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; 
    char* token = strtok(input, " ");
    while (token != NULL) {
        insertAtEnd(&head, token);
        token = strtok(NULL, " ");
    }

    printf("Digite a nova lista de amigos: ");
    fgets(newInput, sizeof(newInput), stdin);
    newInput[strcspn(newInput, "\n")] = 0;  
    Amigo* newFriends = NULL;
    token = strtok(newInput, " ");
    while (token != NULL) {
        insertAtEnd(&newFriends, token);
        token = strtok(NULL, " ");
    }

    printf("Digite o nome do amigo ou 'nao': ");
    fgets(friendInput, sizeof(friendInput), stdin);
    friendInput[strcspn(friendInput, "\n")] = 0;  

    Amigo* temp = newFriends;
    if (strcmp(friendInput, "nao") == 0) {
        while (temp != NULL) {
            insertAtEnd(&head, temp->nome);
            temp = temp->next;
        }
    } else {
        while (temp != NULL) {
            insertBefore(&head, friendInput, temp->nome);
            temp = temp->next;
        }
    }
\
    printf("Nova lista de amigos de Luiggy: ");
    printList(head);

    return 0;
}
