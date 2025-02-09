#include <stdio.h>
#include <stdlib.h>

int max_profit(int* revenue, int days, int cost_per_day) {
    int max_profit = 0;

    for (int start = 0; start < days; start++) {
        int current_profit = 0;
        for (int end = start; end < days; end++) {
            current_profit += revenue[end] - cost_per_day;
            if (current_profit > max_profit) {
                max_profit = current_profit;
            }
        }
    }

    return max_profit;
}

int main() {
    int N;
    
    while (scanf("%d", &N) != EOF) {
        int cost_per_day;
        scanf("%d", &cost_per_day);

        int revenue[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &revenue[i]);
        }

        int result = max_profit(revenue, N, cost_per_day);
        printf("%d\n", result);
    }

    return 0;
}
