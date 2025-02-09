#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int M, T;
    while(scanf("%d %d", &M, &T) == 2){
        if(M == 0 && T == 0)
            break;
        
        int *melody = (int*) malloc(M * sizeof(int));
        int *snippet = (int*) malloc(T * sizeof(int));
        char note[4]; // as notas têm no máximo 2 caracteres (mais o '\0')
        
        for (int i = 0; i < M; i++){
            scanf("%s", note);
            int val = 0;
            switch(note[0]){
                case 'A': val = 0; break;
                case 'B': val = 2; break;
                case 'C': val = 3; break;
                case 'D': val = 5; break;
                case 'E': val = 7; break;
                case 'F': val = 8; break;
                case 'G': val = 10; break;
            }
            if(strlen(note) == 2){
                if(note[1] == '#'){
                    val = (val + 1) % 12;
                } else if(note[1] == 'b'){
                    val = (val + 11) % 12; // equivale a val - 1 mod 12
                }
            }
            melody[i] = val;
        }
        
        for (int i = 0; i < T; i++){
            scanf("%s", note);
            int val = 0;
            switch(note[0]){
                case 'A': val = 0; break;
                case 'B': val = 2; break;
                case 'C': val = 3; break;
                case 'D': val = 5; break;
                case 'E': val = 7; break;
                case 'F': val = 8; break;
                case 'G': val = 10; break;
            }
            if(strlen(note) == 2){
                if(note[1] == '#'){
                    val = (val + 1) % 12;
                } else if(note[1] == 'b'){
                    val = (val + 11) % 12;
                }
            }
            snippet[i] = val;
        }
        
        if(T == 1){
            printf("S\n");
            free(melody);
            free(snippet);
            continue;
        }
        
        int mIntLen = M - 1;
        int tIntLen = T - 1;
        int *mIntervals = (int*) malloc(mIntLen * sizeof(int));
        int *tIntervals = (int*) malloc(tIntLen * sizeof(int));
        
        for (int i = 0; i < mIntLen; i++){
            int diff = melody[i+1] - melody[i];
            mIntervals[i] = (diff % 12 + 12) % 12;
        }
        for (int i = 0; i < tIntLen; i++){
            int diff = snippet[i+1] - snippet[i];
            tIntervals[i] = (diff % 12 + 12) % 12;
        }
        
        int *pi = (int*) malloc(tIntLen * sizeof(int));
        pi[0] = 0;
        for (int i = 1; i < tIntLen; i++){
            int j = pi[i-1];
            while(j > 0 && tIntervals[i] != tIntervals[j])
                j = pi[j-1];
            if(tIntervals[i] == tIntervals[j])
                j++;
            pi[i] = j;
        }
        
        int found = 0;
        int j = 0;
        for (int i = 0; i < mIntLen; i++){
            while(j > 0 && mIntervals[i] != tIntervals[j])
                j = pi[j-1];
            if(mIntervals[i] == tIntervals[j])
                j++;
            if(j == tIntLen){
                found = 1;
                break;
            }
        }
        
        printf("%c\n", found ? 'S' : 'N');
        
        free(melody);
        free(snippet);
        free(mIntervals);
        free(tIntervals);
        free(pi);
    }
    return 0;
}
