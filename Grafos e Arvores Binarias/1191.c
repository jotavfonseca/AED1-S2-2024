#include <stdio.h>
#include <string.h>

typedef struct No {
    char dado;
    struct No *esq, *dir;
} No;

No* construirArvore(char *preOrdem, char *inOrdem, int tam) {
    if (tam <= 0) return NULL;
    
    No *raiz = (No*)malloc(sizeof(No));
    raiz->dado = preOrdem[0];
    raiz->esq = raiz->dir = NULL;
    
    int indiceRaiz = strchr(inOrdem, preOrdem[0]) - inOrdem;
    
    raiz->esq = construirArvore(preOrdem + 1, inOrdem, indiceRaiz);
    raiz->dir = construirArvore(preOrdem + 1 + indiceRaiz, inOrdem + indiceRaiz + 1, tam - indiceRaiz - 1);
    
    return raiz;
}

void imprimirPosOrdem(No *raiz) {
    if (raiz == NULL) return;
    imprimirPosOrdem(raiz->esq);
    imprimirPosOrdem(raiz->dir);
    printf("%c", raiz->dado);
}

void liberarArvore(No *raiz) {
    if (raiz == NULL) return;
    liberarArvore(raiz->esq);
    liberarArvore(raiz->dir);
    free(raiz);
}

int main() {
    char preOrdem[27], inOrdem[27];
    
    while (scanf("%s %s", preOrdem, inOrdem) != EOF) {
        int tam = strlen(preOrdem);
        No *raiz = construirArvore(preOrdem, inOrdem, tam);
        imprimirPosOrdem(raiz);
        printf("\n");
        liberarArvore(raiz);
    }
    
    return 0;
}