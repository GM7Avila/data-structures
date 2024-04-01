#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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


bool isEmpty(const LinkedList *L){
    return (L->begin == NULL && L->last == NULL);
}

void addFirst(LinkedList *L, int value){
    Node *no = createNode(value);
    no->next = L->begin;

    if(isEmpty(L)){
        L->last = no;
    }   

    L->begin = no;
   
}

void addLast(LinkedList *L, int value){
    Node *no = createNode(value);

    if(isEmpty(L)){
        L->begin = no;
        L->last = no;

    } else {
        L->last->next = no;
        L->last = L->last->next;
         
    }
}

// remove o primeiro nó encontrado que possua o valor informado
void removeValue(LinkedList *L, int value){
    if(!isEmpty(L)){

        Node *nextAux = L->begin;

        // caso 1 - elemento está na cabeça da lista
        if(L->begin->value == value) {

            // Se a lista possui um só elemento, que será removido
            if(L->begin == L->last){
                L->last = NULL;
            }
            
            L->begin = L->begin->next;

            free(nextAux);

            return 0;

        }   
        
        // caso 2 - elemento no meio da lista
        // caso 3 - elemento no final da lista
        else {
            nextAux = L->begin->next;
            Node *prevAux = L->begin;  
            
            // O(n)

            // Enquanto há elementos e o valor de nextAux não for igual, avança os ponteiros
            while(nextAux != NULL && nextAux->value != value){
                
                // move os ponteiros -->  
                prevAux = prevAux->next;
                nextAux = nextAux->next;
                
            }

            // node encontrado e apontado pelo ponteiro nextAux
            if(nextAux != NULL){
                prevAux->next = nextAux->next;
                
                // se o elemento a ser removido é o último nó da lista
                // caso 3 - removendo o último elemento da lista
                if(nextAux->next == NULL){
                    L->last = prevAux;
                }
                
                free(nextAux);
            } else {
                printf("O elemento inserido nao se encontra na lista.\n");
            }

            return 0; 

        }
    } else {
        printf("\nErro: nao há nenhum elemento na lista.\n"); 
    }
}

void removeValue_v2(LinkedList *L, int value){
    Node *prevAux = NULL;
    Node *nextAux = L->begin;

    while(nextAux != NULL && nextAux->value != value){
        prevAux = nextAux;
        nextAux = nextAux->next;
    }

    // se achou um nó com valor value
    if(nextAux != NULL){

        if(L->last == nextAux){
            L->last = prevAux;
        }

        if(L->begin == nextAux){
            L->begin = L->begin->next;
        } else {
            prevAux->next = nextAux->next;
        }

        free(nextAux);

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

    if(L->last == NULL){
        printf("L->end = NULL\n");
    } else {
        printf("L->end = %d\n", L->last->value);
    }

    puts("");
}


int main(){

    LinkedList *L = createLinkedList();

    for(int i=1; i<6; i++){
        addFirst(L, i);
    }

    printList(L);

    addLast(L, 2);
    printList(L);

    removeValue_v2(L, 2);
    printList(L);

    removeValue(L, 231);
    printList(L);

    return 0;

}