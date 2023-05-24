#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

#define MAX_SIZE 5

// pilha de inteiros
typedef struct {
    int item [MAX_SIZE];
    int top;
} Stack;

void stackStarter (Stack *p) {
    p -> top = -1;

    for(int i=0; i<MAX_SIZE; i++){
        p->item[i] = 0;
    }
}

void printStack(Stack *p){
    printf("\n");

    for(int i=0; i<MAX_SIZE; i++){
        printf("%d[%d]\n", i, p->item[i]);
    }
}

bool isVoid (Stack *p){
    if (p->top == -1) {
        return true;
    } else return false;
}

bool isFull (Stack *p){
    if (p->top == MAX_SIZE-1){
        return true;
    } else return false;
}

void push(Stack *p, int x){

    // 1º verifica se ela esta cheia
    if(isFull(&p) == true){
        printf("ERRO: Pilha cheia!");
    } else {

        // incrementa o topo
        p->top++;

        // adiciona item ao topo da pilha
        p->item[p->top] = x;


    }

}

void pop(Stack *p){
    int aux;
    
    if(isVoid(&p)==true){
        printf("ERRO> Pilha vazia!");
    } else {

        aux = p->item[p->top];
        p->item[p->top] = 0;

        p->top --;

        printf("SAIU: %d", aux);

    }
}

int main(){

    Stack p;
    stackStarter(&p);

    // inserindo
    push(&p, 15);
    push(&p, 100);
    push(&p, 5);

    printStack(&p);

    pop(&p);

    printStack(&p);

}