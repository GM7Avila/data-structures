// ---> Tabela Hash utilizando Lista Encadeada
#include <stdio.h>
#include <stdlib.h>

// 2 * 15 = 31 (primo)
#define SIZE 31

typedef struct node{
    int key;
    struct node* next;
} Node;

typedef struct{
    Node *start;
    int size;
}List;

void initList(List* l){
    l->start = NULL;
    l->size = 0;
}

void insertList(List* l, int value){
    Node* new = malloc(sizeof(Node));
    if(new){
        new->key = value;
        new->next = l->start;
        l->start = new;
        l->size++;
    } else 
        printf("\n\tMemory error");
}

int searchList(List* l, int value){
    Node* aux = l->start;
    while(aux && aux->key != value)
        aux = aux->next;
    if(aux)
        return aux->key;
}

void printList(List* l){
    Node* aux = l->start;
    printf("Size: %d: ", l->size);
    while(aux){
        printf("%d ", aux->key);
        aux = aux->next;
    }
}

void initTable(List t[]){
    for(int i=0; i<SIZE; i++){
        initList(&t[i]);
    }
}

int hashFunction(int key){
    return key % SIZE;
}

void insert(List t[], int value){
    int id = hashFunction(value);
    insertList(&t[id], value);
}

int search(List t[], int value){
    int id = hashFunction(value);
    printf("\n\t Key: %d\n", id);
    return searchList(&t[id], value);
}

void printHashTable(List t[]){
    printf("\n\t--> HASH TABLE:\n");
    for(int i=0; i<SIZE; i++){
        printf("[%2d] ", i);
        printList(&t[i]);
        printf("\n");
    }
}

int main(){

    int value, opt;
    List table[SIZE];

    initTable(table);

    do{
        printf("\n\tHASH!\n\t0 - Exit\n\t1 - Insert\n\t2 - Search\n\t3 - Print Table\n\n\t=> ");
        scanf("%d", &opt);

        switch(opt){
            case 0: 
                break;
            case 1: 
                printf("\tWhat value do you want to insert? ");
                scanf("%d", &value);

                insert(table, value);

                break;
            case 2:
                printf("\tValue to search: ");
                scanf("%d", &value);
                
                int searchResult = search(table, value);

                if(searchResult == 0){
                    printf("\n\t Not found!");
                } else {
                    printf("\n\t Value found: %d!", value);
                }

                break;
            case 3:
                printHashTable(table);
                break;
            default:
                printf("Invalid argument");
        }

    } while(opt != 0);

    return 0;

}
