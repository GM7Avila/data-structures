// aritmética de ponteiros na prática
#include <stdio.h>

int main(){

    int v1[5] = {0, 1, 2, 3, 4};
    int *v2, *p;
    int i;

    p = v1;
    p[3] = p[4] = 10;

    v2 = (int*) malloc(5 * sizeof(int));

    for(i=0; i<5; i++){
        v2[i] = v1[i];
    }

    free(v2);
    v2 = NULL;
}
