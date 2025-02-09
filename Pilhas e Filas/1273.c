#include <stdio.h>
#include <string.h>

int main(){
    int N, i, j, max, len;
    int firstCase = 1;
    while(scanf("%d", &N) == 1 && N){
        if(!firstCase)
            printf("\n");
        firstCase = 0;
        char words[55][55];
        max = 0;
        for(i = 0; i < N; i++){
            scanf("%s", words[i]);
            len = strlen(words[i]);
            if(len > max)
                max = len;
        }
        for(i = 0; i < N; i++){
            len = strlen(words[i]);
            for(j = 0; j < max - len; j++){
                printf(" ");
            }
            printf("%s\n", words[i]);
        }
    }
    return 0;
}
