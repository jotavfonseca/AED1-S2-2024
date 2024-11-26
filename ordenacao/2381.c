#include <stdio.h>
#include <string.h>

void InsertionSelection(char alunos[][21], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(alunos[j], alunos[min]) < 0) {
                min = j;
            }
        }
        if (min != i) {
            char temp[21];
            strcpy(temp, alunos[i]);
            strcpy(alunos[i], alunos[min]);
            strcpy(alunos[min], temp);
        }
    }
}

int main() {
    
    int qtdAlunos, ganhador;
    scanf("%d %d", &qtdAlunos, &ganhador);
    
    char alunos[qtdAlunos][21];
    for (int i = 0; i < qtdAlunos; i++) {
        scanf("%s", alunos[i]);
    }
    InsertionSelection(alunos, qtdAlunos);
    printf("%s\n", alunos[ganhador - 1]);

    return 0;
}