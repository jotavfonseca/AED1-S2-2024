#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char word[17];  // até 16 letras + '\0'
    int value;
} Entry;

// Função de comparação para ordenar o vetor do dicionário (por ordem lexicográfica)
int cmpEntry(const void *a, const void *b) {
    const Entry *ea = (const Entry *)a;
    const Entry *eb = (const Entry *)b;
    return strcmp(ea->word, eb->word);
}

// Função de comparação usada pelo bsearch (compara a chave – palavra – com a entrada do dicionário)
int cmpKey(const void *key, const void *elem) {
    return strcmp((const char *) key, ((const Entry *)elem)->word);
}

int main(){
    int m, n;
    // Enquanto for possível ler um caso de teste (dois inteiros: m e n)
    while (scanf("%d %d", &m, &n) == 2) {
        Entry dict[1100];  // M <= 1000, então 1100 é suficiente
        for (int i = 0; i < m; i++){
            scanf("%s %d", dict[i].word, &dict[i].value);
        }
        // Ordena o dicionário para permitir busca binária
        qsort(dict, m, sizeof(Entry), cmpEntry);
        
        // Processa cada uma das N descrições de cargo
        for (int i = 0; i < n; i++){
            int salary = 0;
            char token[50];  // buffer para ler cada palavra (suficiente, pois as palavras têm até 16 letras)
            // A descrição é composta por um conjunto de tokens até encontrarmos o token "."
            while (scanf("%s", token) == 1) {
                if (strcmp(token, ".") == 0)
                    break;
                // Procura a palavra no dicionário usando bsearch
                Entry *found = (Entry *) bsearch(token, dict, m, sizeof(Entry), cmpKey);
                if (found != NULL)
                    salary += found->value;
            }
            printf("%d\n", salary);
        }
    }
    return 0;
}
