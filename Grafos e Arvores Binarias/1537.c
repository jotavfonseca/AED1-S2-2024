#include <stdio.h>
#define MOD 1000000009

long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() {
    int N;
    long long fat[100001];
    
    fat[0] = 1;
    for (int i = 1; i <= 100000; i++) {
        fat[i] = (fat[i-1] * i) % MOD;
    }
    
    long long inv6 = mod_exp(6, MOD-2, MOD);
    
    while (1) {
        scanf("%d", &N);
        if (N == 0) break;
        
        long long resultado = (fat[N] * inv6) % MOD;
        printf("%lld\n", resultado);
    }
    
    return 0;
}