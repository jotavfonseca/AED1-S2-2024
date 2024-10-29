#include <stdio.h>

int VerificaLinha(int matriz[9][9]) {
    int i, j, k;
    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            for(k = j + 1; k < 9; k++){
                if(matriz[i][j] == matriz[i][k])
                    return 0;
            }
        }
    }
        
    return 1;

}

int VerificaColuna(int matriz[9][9]) {
    int i, j, k;
    for(j = 0; j < 9; j++){
        for(i = 0; i < 9; i++){
            for(k = i + 1; k < 9; k++){
                if(matriz[i][j] == matriz[k][j])
                    return 0;
            }
        }
    }
                
    return 1;
}

int VerificaSubMatriz(int mini[3][3]) {
    int i, j, num, existe;
    for(num = 1; num <= 9; num++) {
        existe = 0;
        for(i = 0; i < 3; i++){
            for(j = 0; j < 3; j++){
                if(mini[i][j] == num)
                    existe++;
            }
        }
            
        if(existe > 1)
            return 0;
    }
    return 1;
}

int VerificaMatrizes(int matriz[9][9]) {
    int i, j, k, l, submatriz[3][3];
    for(i = 0; i < 9; i += 3){
        for(j = 0; j < 9; j += 3) {
            for(k = 0; k < 3; k++){
                for(l = 0; l < 3; l++){
                    submatriz[k][l] = matriz[i+k][j+l];
                }
            }
            if(!VerificaSubMatriz(submatriz))
                return 0;
        }
    }
        
    return 1;
}

int main() {

    int numMat, index, matriz[9][9], i, j;

    scanf("%d", &numMat);

    for(index = 1; index <= numMat; index++) {
        for(i = 0; i < 9; i++){
            for(j = 0; j < 9; j++){
                scanf("%d", &matriz[i][j]);
            }
        }

        printf("Instancia %d\n", index);
        if(VerificaLinha(matriz) && VerificaColuna(matriz) && VerificaMatrizes(matriz))
            printf("SIM\n");
        else
            printf("NAO\n");
        printf("\n");
    }

    return 0;
}
