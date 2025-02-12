#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LENGTH 11

bool next_permutation(char *str, int len) {
    int i = len - 2;
    while (i >= 0 && str[i] >= str[i + 1]) {
        i--;
    }
    if (i < 0) {
        return false;
    }
    int j = len - 1;
    while (str[j] <= str[i]) {
        j--;
    }
    char temp = str[i];
    str[i] = str[j];
    str[j] = temp;
    for (int left = i + 1, right = len - 1; left < right; left++, right--) {
        temp = str[left];
        str[left] = str[right];
        str[right] = temp;
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    getchar(); // remove newline character after integer input

    char strings[MAX_LENGTH];

    while (n--) {
        fgets(strings, MAX_LENGTH, stdin);
        strings[strcspn(strings, "\n")] = 0; // remove newline character
        int len = strlen(strings);

        qsort(strings, len, sizeof(char), (int(*)(const void*, const void*))strcmp);

        do {
            printf("%s\n", strings);
        } while (next_permutation(strings, len));

        printf("\n"); // Ensure a blank line after each set of permutations
    }

    return 0;
}
