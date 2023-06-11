#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    int value;
    struct node *next; 
} Node;

typedef struct linkedList {
    Node *begin;
    Node *last;
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
    
    if(L->begin == NULL){
        L->last = no;
    } else {
        no->next = L->begin;
    }         
    
    L->begin = no;

}

void addLast(LinkedList *L, int value){
    Node *no = createNode(value);

    // Lista vazia
    if(L->begin == NULL){
        L->begin = no;
        L->last = no;

    } else {
        L->last->next = no;
        L->last = L->last->next;
         
    }
}

void printList(const LinkedList *L){
    
    // Primeiro nó
    Node *pNode = L->begin;
    printf("L -> ");

    // Enquanto pNode não aponta para um elemento NULL
    while(pNode != NULL){
        printf("%d -> ", pNode->value);
        pNode = pNode->next;
    }
    printf("NULL\n");
}


int main(){
    LinkedList *L = createLinkedList();

    for(int i=1; i<6; i++){
        addFirst(L, i);
    }

    puts("\n");
    printList(L);

    addLast(L, 1000);

    puts("\n");
    printList(L);

    return 0;

}