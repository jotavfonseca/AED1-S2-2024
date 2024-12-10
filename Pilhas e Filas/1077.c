#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

typedef struct pilha{
    char valor;
    struct pilha *next;
}pilha;

pilha *create(char valor){
    pilha *novo = (pilha *)malloc(sizeof(pilha));
    novo->valor = valor;
    novo->next = NULL;
    return novo;
}

void push(char valor,pilha **top){
    pilha* novo = create(valor);
    novo->next = *top;
    *top = novo;
}

char pop(pilha **top){
    if (*top == NULL) return '\0';
    pilha* aux = *top;
    *top = (*top)->next;
    char valor = aux->valor; 
    free(aux);
    return valor;
}

char topo(pilha *top) { 
    if (top == NULL) { 
        return '\0'; 
    } 
    return top->valor;
}

int precedencia(char operador) { 
    switch (operador) { 
        case '^': return 3;
        case '*': 
        case '/': return 2; 
        case '+': 
        case '-': return 1; 
        default: return 0; 
    } 
}

int Digito(char c) { 
    return c >= '0' && c <= '9';
}

int Letra(char c) { 
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

void infixaParaPosfixa(char* expressao, char* resultado){
    pilha *operadores = NULL;
    int k = 0;
    for (int i = 0; i < strlen(expressao); i++){
        if (Digito(expressao[i]) || Letra(expressao[i])){
            resultado[k++] = expressao[i];
        }else if (expressao[i] == '('){
            push(&operadores, expressao[i]);
        }else if (expressao[i] == ')'){
            while(!empty(operadores) && topo(operadores) != '('){
                resultado[k++] = pop(&operadores);
            }
            pop(&operadores);
        }else{
            while(!empty(operadores) && precedencia(topo(operadores)) >= precedencia(expressao[i])){
                resultado[k++] = pop(&operadores);
            }
            push(&operadores, expressao[i]);
        }
    }
    while (!empty(operadores)){
        resultado[k++] = pop(&operadores);
    }
    resultado[k] = '\0';
}

int empty(pilha *top){
    return top == NULL;
}

int main() {
    int N;
    scanf("%d", &N);
    getchar();
    
    char expressao[300];
    for (int i = 0; i < N; i++){
        fgets(expressao, sizeof(expressao), stdin);
        expressao[strcspn(expressao, "\n")] = 0;

        char resultado[300];
        infixaParaPosfixa(expressao, resultado);
        printf("%s\n", &resultado);
    }

    return 0;
}