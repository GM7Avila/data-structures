#include <stdio.h>
#include <stdlib.h>

int main(){

    char *v;

    for (int i=0; i<10000000; i++){
        v = (char*)calloc(10, sizeof(char));
    }

    return 0;

}