#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

typedef struct pilha{
    char valor;
    struct pilha *next;
}pilha;

pilha *create(char valor){
    pilha *novo = (pilha *)malloc(sizeof(malloc));
    novo->valor = valor;
    novo->next = NULL;
    return novo;
}

void push(char valor, pilha **top){
    pilha* novo = create(valor);
    novo->next = *top;
    *top = novo;
    // return novo;
}

char pop(pilha **top){
    if (*top == NULL) return '/0';
    pilha* aux = *top;
    *top = (*top)->next;
    char valor = aux->valor;
    free(aux);
    return valor;
}

int empty(pilha *top){
    return top == NULL;
}

int contarDiamantes(char* mina){
    pilha *top = NULL;
    int cont = 0;
    for (int i = 0; i < strlen(mina); i++){
        if (mina[i] == '<'){
            push(mina[i], &top);
        }else if(mina[i] == '>' && !empty(top)){
            pop(&top);
            cont++;
        }
    }
    while (!empty(top)){
        pop(&top);
    }
    return cont;
}

int main() {
    int n;
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++){
        char mina[1001];
        fgets(mina, sizeof(mina), stdin);
        mina[strcspn(mina, "\n")] = 0;
        printf("%d\n", contarDiamantes(mina));
    }
    
    return 0;
}