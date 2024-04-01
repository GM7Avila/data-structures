#include <stdio.h>
#include <stdlib.h>

int main(){
    float z = 2.5;
    float *fp;

    fp = &z; //fp = 5000 (endereço ficticio)

    printf("*&z = %f\n", *&z);
    printf("*fp = %f\n", *fp); // *(&z)
    printf("**&fp = %f\n", **&fp);
}
