#include <stdio.h>

void increment1(int a){
    a = a + 1;
}

void increment2(int * pointer){
    *pointer = *pointer + 1;
}

int main() {
    int a = 10;
    printf("a: %d \n&a: %p\n\n", a, &a);
    
    int * pointer = &a;
    
    printf("pointer: %p \n&pointer: %p\n*pointer: %d\n", pointer, &pointer, *pointer);

    increment1(a);
    printf("\nIncrement 1: a + 1 = %d\n", a);
    
    increment2(pointer);
    printf("Increment 2: a + 1 = %d", a);
    return 0;
}
