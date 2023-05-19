#include <stdio.h>
#include <stdlib.h>

#define N 5

int main(){

    // vetor estático
    int ve[N] = {5,4,3,2,1};

    // vetor dinâmico
    int *vd = (int*) malloc(N * sizeof(int));

    for(int i=0; i<N; i++){
        vd[i] = ve[i];
    }

    free(vd);

    return 0;

}
