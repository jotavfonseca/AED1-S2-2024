#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

typedef struct pilha{
    char valor;
    struct pilha *next;
}pilha;

pilha* create(char valor){
    pilha *novo = (pilha *)malloc(sizeof(pilha));
    novo->valor = valor;
    novo->next = NULL;
    return novo;
}

void insere(char valor, pilha **top){
    pilha* novo = create(valor);
    novo->next = *top;
    *top = novo; 
}

char desempilhar(pilha **top){
    if (*top == NULL) {
        return '/0';
    }
    pilha* aux = *top;
    *top = (*top)->next;
    char valor = aux->valor;
    free(aux);
    return valor;
}

int empty(pilha *top) { 
    return top == NULL;
}

int verificaEq(const char* eq){
    pilha *top = NULL;
    for (int i = 0; i < strlen(eq); i++){
        char caracter = eq[i];
        if (caracter == '(') {
            insere(caracter, &top);
        }else if(caracter == ')'){
            if (empty(top)){
                return 0;
            }
            desempilhar(&top);
        }
    }
    int result = empty(top);
    while(!empty(top)){
        desempilhar(&top);
    }
    return result;
}



int main() {
    int n;
    scanf("%d", &n);
    getchar();

    char eq[1000];
    for (int i = 0; i < n; i++){
        fgets(eq, sizeof(eq), stdin);
        eq[strcspn(eq, "\n")] = 0;
        if (verificaEq(eq)){
            printf("correct\n");
        }else{
            printf("incorrect\n");
        }
    }
    
    return 0;
}