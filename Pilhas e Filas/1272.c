#include <stdio.h>
#include <string.h>

int main(){
    int t;
    scanf("%d", &t);
    getchar(); // Consome o '\n' que segue o número de casos
    char line[60]; // Considerando até 50 caracteres + '\n' + '\0'
    
    for (int i = 0; i < t; i++){
        // Lê a linha inteira (incluindo possíveis espaços no início ou fim)
        fgets(line, sizeof(line), stdin);
        
        // Remove a quebra de linha, se presente
        size_t len = strlen(line);
        if(len > 0 && line[len-1] == '\n'){
            line[len-1] = '\0';
        }
        
        // Para cada caractere, se não for espaço e o caractere anterior for espaço (ou for o primeiro caractere),
        // então é a primeira letra de uma palavra.
        for (int j = 0; line[j] != '\0'; j++){
            if (line[j] != ' ' && (j == 0 || line[j-1] == ' ')) {
                putchar(line[j]);
            }
        }
        putchar('\n');
    }
    return 0;
}
