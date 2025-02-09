#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    while (1) {
        scanf("%d", &n);
        if (n == 0) break;

        while (1) {
            int target[n];
            int stack[n];
            int top = -1;
            int i, j = 0;

            for (i = 0; i < n; i++) {
                scanf("%d", &target[i]);
                if (target[i] == 0) break;
            }

            if (target[0] == 0) {
                printf("\n");
                break;
            }

            for (i = 1; i <= n; i++) {
                stack[++top] = i;

                while (top != -1 && stack[top] == target[j]) {
                    top--;
                    j++;
                }
            }

            if (top == -1) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
    }

    return 0;
}
