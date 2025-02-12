#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main() {
    int P, M, F, Q, B, K;
    scanf("%d", &P);
    int port[P];
    for (int i = 0; i < P; i++) scanf("%d", &port[i]);
    
    scanf("%d", &M);
    int mat[M];
    for (int i = 0; i < M; i++) scanf("%d", &mat[i]);
    
    scanf("%d", &F);
    int fis[F];
    for (int i = 0; i < F; i++) scanf("%d", &fis[i]);
    
    scanf("%d", &Q);
    int qui[Q];
    for (int i = 0; i < Q; i++) scanf("%d", &qui[i]);
    
    scanf("%d", &B);
    int bio[B];
    for (int i = 0; i < B; i++) scanf("%d", &bio[i]);
    
    scanf("%d", &K);
    
    int total = P * M * F * Q * B;
    int *valores = (int*) malloc(total * sizeof(int));
    int idx = 0;
    
    for (int i = 0; i < P; i++)
        for (int j = 0; j < M; j++)
            for (int k = 0; k < F; k++)
                for (int l = 0; l < Q; l++)
                    for (int m = 0; m < B; m++)
                        valores[idx++] = port[i] + mat[j] + fis[k] + qui[l] + bio[m];
    
    qsort(valores, total, sizeof(int), compare);
    
    long long soma = 0;
    for (int i = 0; i < K; i++) soma += valores[i];
    
    printf("%lld\n", soma);
    
    free(valores);
    return 0;
}
