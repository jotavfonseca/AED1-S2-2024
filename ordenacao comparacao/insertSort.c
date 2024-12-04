#include <stdio.h>
#include <time.h>

void insertionSort(int vetor[], int n) {
    for (int i = 1; i < n; i++) {
        int key = vetor[i]; 
        int j = i - 1;

        while (j >= 0 && vetor[j] > key) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = key; 
    }
}


int main() {
    int vetor[400000];
    int range = 20000;
    srand(time(NULL));

    while (range < 400000) {
        for(int i = 0; i < range; i++){
            vetor[i] = rand() % range;
        }

        clock_t start = clock();
        insertionSort(vetor, range);
        clock_t end = clock();

        double exec = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Tamanho do array: %d, Tempo: %.6f segundos\n", range, exec);

        range += 20000;
    }

    

    return 0;
}
