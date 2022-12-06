#include <stdio.h>
#include <stdlib.h>

int main(){

    int vs[5] = {0, 10, 20, 30, 40};

    puts("### VETOR ESTATICO");
    printf("&vs = %p, vs = %p\n", &vs, vs);
    
    for (int i = 0; i < 5; i++){

        printf("&vs[%d] = %p, vs[%d] = %d\n" , i, &vs[i], i, vs[i]);

    }

    puts("\n");

    return 0;

}
/*
### VETOR ESTATICO

&vs[0] = 0061FF08, vs[0] = 0
&vs[1] = 0061FF0C, vs[1] = 10
&vs[2] = 0061FF10, vs[2] = 20
&vs[3] = 0061FF14, vs[3] = 30
&vs[4] = 0061FF18, vs[4] = 40

*/