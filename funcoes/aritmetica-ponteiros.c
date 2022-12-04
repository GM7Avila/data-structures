#include <stdio.h>

int main(){

    int v[5] = {10, 5, 4, 16, 1};
    printf ("&v = %p, v = %p\n\n", &v, v);
    
    for(int i=0; i<5; i++){
        printf("&v[%d] = %p, v[%d] = %d\n", i, &v[i], i, v[i]);
        printf("(v + %d) = %p, *(v + %d) = %d\n\n", i, (v+i), i, *(v+i));
    }

    return 0;
}

//O símbolo v é uma constante que representa o endereço inicial do vetor.
//Logo, sem indexação, v aponta(guarda a referência) para o primeiro elemento do vetor.
//v retorna o &v[0] , v[0] = valor em v[0] , ou seja *v

// ex.: v[3] = *v(+3) = *(S116) = 16;