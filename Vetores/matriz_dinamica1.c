#include <stdio.h>
#include <stdlib.h> //malloc, calloc, free, NULL, etc

int main(){

    // ===================== ALOC. DINAMICA =====================
    int rows = 2;
    int cols = 4;
    
    // cria um vetor dinamico de tamanho 2(rows) m[0] e m[1] - vetor de ponteiro de inteiro
    int ** m = (int**) calloc(rows, sizeof(int*));

    // para cada linha, m[i] aponta para novos blocos(int) que representarão as colunas
    for(int i=0; i<rows; i++){
        // m[0] / m[1] = endereço das linhas (bloco de inteiros) - colunas
        m[i] = (int*) calloc(cols, sizeof(int));
    }
    // ==========================================================

    int count = 0;

    printf("&m = %p, m = %p\n\n", &m, m);

    for (int i = 0; i < rows; i++) {
        printf("&m[%d] = %p, m[%d] = %p\n", i, &m[i], i, m[i]);

        for (int j = 0; j < cols; j++) {
            // m[i][j] = count;
            // count++;
            m[i][j] = count++;

            printf("&m[%d][%d] = %p, m[%d][%d] = %d\n",
                    i, j, &m[i][j],
                    i, j, m[i][j]);
        }
        puts("");
    }
    
    /********* FALTA A DESALOCAÇÃO DA MATRIZ *********/

    return 0;

}