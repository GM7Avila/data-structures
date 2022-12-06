#include <stdio.h>
#include <stdlib.h>

int main(){
    // ##### vs -> vetor na stack
    int vs[5] = {0, 10, 20, 30, 40};

        puts("### VETOR ESTATICO");
        printf("&vs = %p, vs = %p\n", &vs, vs);
        
        for (int i = 0; i < 5; i++){

            printf("&vs[%d] = %p, vs[%d] = %d\n" , i, &vs[i], i, vs[i]);

        }

    puts("\n");

    // ##### vh -> vetor na heap
    int *vh_malloc = (int *)malloc(5 * sizeof(int)); //os elementos possuem "lixo de memória"

        puts("### VETOR DINAMICO com MALLOC");
        
        printf("&vh_malloc = %p, vh_malloc = %p\n", &vh_malloc, vh_malloc);

        for (int i = 0; i < 5; i++){

            printf("&vh_malloc[%d] = %p, vh_malloc[%d] = %d\n" , i, &vh_malloc[i], i, vh_malloc[i]);

        }
        
        puts("\n");


    int *vh_calloc = (int *)calloc(5, sizeof(int)); //os elementos possuem 0 (null para ponteiro) como valor inicial

        puts("### VETOR DINAMICO com CALLOC");
        
        printf("&vh_calloc = %p, vh_calloc = %p\n", &vh_calloc, vh_calloc);

        for (int i = 0; i < 5; i++){

            printf("&vh_calloc[%d] = %p, vh_calloc[%d] = %d\n" , i, &vh_calloc[i], i, vh_calloc[i]);

        }
        
        puts("\n");

    return 0;

    //vetores dinâmicos não desalocados...

}

/*

### VETOR ESTATICO
&vs = 0061FF04, vs = 0061FF04 //stack
&vs[0] = 0061FF04, vs[0] = 0 //stack
&vs[1] = 0061FF08, vs[1] = 10 //stack
&vs[2] = 0061FF0C, vs[2] = 20 //stack
&vs[3] = 0061FF10, vs[3] = 30 //stack
&vs[4] = 0061FF14, vs[4] = 40 //stack


### VETOR DINAMICO com MALLOC
&vh_malloc = 0061FF00, vh_malloc = 00771C40 //stack - heap vh_malloc[0]
&vh_malloc[0] = 00771C40, vh_malloc[0] = 7804536 //heap
&vh_malloc[1] = 00771C44, vh_malloc[1] = 7798976 //heap
&vh_malloc[2] = 00771C48, vh_malloc[2] = 150994953 //heap
&vh_malloc[3] = 00771C4C, vh_malloc[3] = 60563 //heap
&vh_malloc[4] = 00771C50, vh_malloc[4] = 7804536 //heap

### VETOR DINAMICO com CALLOC //SEM LIXO DE MEMÓRIA
&vh_calloc = 0061FEF8, vh_calloc = 00AD1C60
&vh_calloc[0] = 00AD1C60, vh_calloc[0] = 0 
&vh_calloc[1] = 00AD1C64, vh_calloc[1] = 0
&vh_calloc[2] = 00AD1C68, vh_calloc[2] = 0
&vh_calloc[3] = 00AD1C6C, vh_calloc[3] = 0
&vh_calloc[4] = 00AD1C70, vh_calloc[4] = 0

*/