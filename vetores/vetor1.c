/*

Programa com vetores estáticos e dinâmico: 
- Crie uma função que recebe o ponteiro de um vetor e seu tamanho e imprima os elementos do vetor;
- Crie uma função que recebe o ponteiro de um vetor via colchetes[] e seu tamanho e imprima os elementos do vetor;
- Imprima os endereços de memória e valores de vetor na main e dentro de cada função.

*/

// ### VETOR COMO PARÂMETRO PARA UMA FUNÇÃO

#include <stdio.h>
#include <stdlib.h>

int soma_vetor_modf(int v[], int n, int modf){
    for (int i = 0; i < n; i++){
        v[i] += modf;
    }
}

void print_vetor(int *v, int n){ //int * v = v[] pois ambos utilizam o primeiro endereço alocado no bloco;
    for(int i = 0; i< n; i++){
        printf("&v[%d] = %p, v[%d] = %d\n" , i, &v[i], i, v[i]);
    } puts("");
}

int main(){
    
    puts("### VETOR ESTATICO");
    int vs[5] = {0, 10, 20, 30, 40};
    
    print_vetor(vs, 5);
    soma_vetor_modf(vs, 5, 9);
    print_vetor(vs, 5);

    puts("### VETOR DINAMICO com CALLOC");
    int * vh = (int *)calloc(5, sizeof(int));
    for (int i = 0; i < 5; i++){
        vh[i] = i*100; //diferenciando valores
    }

    print_vetor(vh, 5);
    soma_vetor_modf(vh, 5, 9);
    print_vetor(vh, 5);
    
    //desalocando vetor dinamico
    free(vh); 
    vh = NULL;

    return 0;

}