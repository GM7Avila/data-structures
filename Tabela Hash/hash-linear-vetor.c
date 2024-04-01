// ---> Tabela Hash Linear utilizando vetor
#include <stdio.h>
#include <stdlib.h>

// 2 * 15 = 31 (primo)
#define SIZE 31

void initTable(int t[]){
    for(int i=0; i<SIZE; i++){
        t[i] = 0; // zero não faz parte do conjunto neste caso
    }
}

int hashFunction(int key){
    return key % SIZE;
}

void insert(int t[], int value){
    int id = hashFunction(value);
    while(t[id]!= 0){
        id = hashFunction(id+1);
    }
    t[id] = value;
}

int search(int t[], int value){
    int id = hashFunction(value);
    printf("\n\t Key: %d\n", id);
    while(t[id]!= 0){
        if(t[id] == value){
            return t[id];
        } else {
            id = hashFunction(id+1);
        }
    }

    return 0;
}

void printHashTable(int t[]){
    printf("\n\t--> HASH TABLE:\n");
    for(int i=0; i<SIZE; i++){
        printf("\t [%d]: %d\n", i, t[i]);
    }
}

int main(){

    int table[SIZE], value, opt;

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