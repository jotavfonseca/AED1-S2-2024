#include <stdio.h>
#include <string.h>

int main() {
    char cpf[15];
    
    while (scanf("%s", cpf) != EOF) {
        int digits[11], i, sum1 = 0, sum2 = 0;

        digits[0] = cpf[0] - '0';
        digits[1] = cpf[1] - '0';
        digits[2] = cpf[2] - '0';
        digits[3] = cpf[4] - '0';
        digits[4] = cpf[5] - '0';
        digits[5] = cpf[6] - '0';
        digits[6] = cpf[8] - '0';
        digits[7] = cpf[9] - '0';
        digits[8] = cpf[10] - '0';
        digits[9] = cpf[12] - '0';
        digits[10] = cpf[13] - '0';

        for (i = 0; i < 9; i++)
            sum1 += digits[i] * (i + 1);

        int b1 = sum1 % 11;
        if (b1 == 10) b1 = 0;

        for (i = 0; i < 9; i++)
            sum2 += digits[i] * (9 - i);

        int b2 = sum2 % 11;
        if (b2 == 10) b2 = 0;

        if (b1 == digits[9] && b2 == digits[10])
            printf("CPF valido\n");
        else
            printf("CPF invalido\n");
    }

    return 0;
}
