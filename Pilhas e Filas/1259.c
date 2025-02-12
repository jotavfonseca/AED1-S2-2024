#include <stdio.h>
#include <stdlib.h>

int comp(const void *a, const void *b) {
    int A = *(const int *)a;
    int B = *(const int *)b;
    
    // Ambos pares: ordem crescente
    if (A % 2 == 0 && B % 2 == 0)
        return A - B;
    
    // Ambos ímpares: ordem decrescente
    if (A % 2 != 0 && B % 2 != 0)
        return B - A;
    
    // Se A é par e B é ímpar, A vem antes (retorna valor negativo)
    if (A % 2 == 0)
        return -1;
    
    // Caso contrário, A é ímpar e B é par: A vem depois (retorna valor positivo)
    return 1;
}

int main(){
    int n;
    scanf("%d", &n);
    
    int *numeros = (int*) malloc(n * sizeof(int));
    if(numeros == NULL) {
        return 1;
    }
    
    for (int i = 0; i < n; i++){
        scanf("%d", &numeros[i]);
    }
    
    qsort(numeros, n, sizeof(int), comp);
    
    for (int i = 0; i < n; i++){
        printf("%d\n", numeros[i]);
    }
    
    free(numeros);
    return 0;
}
