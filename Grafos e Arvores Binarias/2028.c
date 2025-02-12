#include <stdio.h>

int main() {
    int N, caso = 1;
    while (scanf("%d", &N) != EOF) {
        int total = 1;
        for (int i = 1; i <= N; i++) total += i;
        printf("Caso %d: %d numero%s\n", caso++, total, total > 1 ? "s" : "");
        for (int i = 0; i <= N; i++)
            for (int j = 0; j < (i == 0 ? 1 : i); j++)
                printf("%d%s", i, --total ? " " : "\n");
        printf("\n");
    }
    return 0;
}
