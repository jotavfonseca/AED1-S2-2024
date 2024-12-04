#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Separa(int vetor[], int low, int high) {
    int j, k, aux;
    int pivo = vetor[high]; 
    j = low;

    for (k = low; k < high; k++) {
        if (vetor[k] <= pivo) {
            aux = vetor[j]; 
            vetor[j] = vetor[k]; 
            vetor[k] = aux;
            j++;
        }
    }

    vetor[high] = vetor[j];
    vetor[j] = pivo;
    return j;
}

void quickSort(int vetor[], int low, int high) {
    if (low < high) {
        int pi = Separa(vetor, low, high); 

        quickSort(vetor, low, pi - 1);
        quickSort(vetor, pi + 1, high);
    }
}

int main() {
    int vetor[400000];
    int range = 20000;

    srand(time(NULL));

    while (range <= 400000) {
        for (int i = 0; i < range; i++) {
            vetor[i] = rand() % range;
        }

        clock_t start = clock();
        quickSort(vetor, 0, range - 1);
        clock_t end = clock();

        double exec = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Tamanho do array: %d, Tempo: %.6f segundos\n", range, exec);

        range += 20000; 
    }

    return 0;
}
