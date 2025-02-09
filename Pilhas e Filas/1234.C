#include <stdio.h>
#include <ctype.h>
#include <string.h>

void to_dancing_sentence(char *sentence) {
    int length = strlen(sentence);
    int upper = 1; // Começa com maiúscula

    for (int i = 0; i < length; i++) {
        if (sentence[i] != ' ') {
            if (upper) {
                sentence[i] = toupper(sentence[i]);
            } else {
                sentence[i] = tolower(sentence[i]);
            }
            upper = !upper; // Alterna entre maiúscula e minúscula
        }
    }
}

int main() {
    char sentence[51];

    while (fgets(sentence, sizeof(sentence), stdin)) {
        // Remove o caractere de nova linha, se presente
        sentence[strcspn(sentence, "\n")] = 0;

        to_dancing_sentence(sentence);

        printf("%s\n", sentence);
    }

    return 0;
}
