#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int value;
    struct node *next; 
} Node;

typedef struct linkedList {
    Node *begin;
} LinkedList;


LinkedList *createLinkedList(){
    LinkedList *L = (LinkedList *) calloc(1, sizeof(LinkedList));
    L->begin = NULL;

    return L;
}

Node *createNode(int value){
    Node *N = (Node *) calloc(1, sizeof(Node));
    N->value = value;
    N->next = NULL;

    return N;
}

void addFirst(LinkedList *L, int value){
    
    Node *no = createNode(value);
    
    // Lista não vazia vazia
    if(L->begin != NULL){
        no->next = L->begin;
    }         
    
    L->begin = no;

}
