#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int vetor[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int esq[n1], dir[n2];

    for (int i = 0; i < n1; i++)
        esq[i] = vetor[left + i];
    for (int j = 0; j < n2; j++)
        dir[j] = vetor[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (esq[i] <= dir[j]) {
            vetor[k] = esq[i];
            i++;
        } else {
            vetor[k] = dir[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        vetor[k] = esq[i];
        i++;
        k++;
    }

    while (j < n2) {
        vetor[k] = dir[j];
        j++;
        k++;
    }
}

void mergeSort(int vetor[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(vetor, left, mid);
        mergeSort(vetor, mid + 1, right);

        merge(vetor, left, mid, right);
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
        mergeSort(vetor, 0, range - 1);
        clock_t end = clock();

        double exec = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Tamanho do array: %d, Tempo: %.6f segundos\n", range, exec);

        range += 20000;
    }

    return 0;
}
