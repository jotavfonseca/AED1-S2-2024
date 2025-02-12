#include <stdio.h>
#include <stdbool.h>

bool has_unique_digits(int num) {
    bool digit_seen[10] = { false };

    while (num > 0) {
        int digit = num % 10;
        if (digit_seen[digit]) {
            return false;
        }
        digit_seen[digit] = true;
        num /= 10;
    }
    return true;
}

int main() {
    int N, M;
    
    while (scanf("%d %d", &N, &M) != EOF) {
        int count = 0;
        for (int i = N; i <= M; i++) {
            if (has_unique_digits(i)) {
                count++;
            }
        }
        printf("%d\n", count);
    }

    return 0;
}
