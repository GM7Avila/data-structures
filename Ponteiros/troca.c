#include <stdio.h>

int main (){
    
    int a = 10;
    int b = 20;

    troca(&a, &b);
}

void troca (int *x, int *y) { 
        int aux = *x;
        *x = *y;
        *y = aux;
}