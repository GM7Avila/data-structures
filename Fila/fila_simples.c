#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *next;
} Node;

int isVoid(Node **f){
    if(*f == NULL) {
        return 1;
    } else 
        return 0;
}
 
void inserir(Node **f, int num){

    Node *aux, *new = malloc(sizeof(Node));

    if( new != NULL ){

        printf("\n\nNode *aux, *new = malloc(sizeof(Node));");

        printf("\n*f: %p", *f);
        printf("\nf: %p", f);
        printf("\n&f: %p", &f);

        printf("\n\n*new: %p", *new);
        printf("\nnew: %p", new);
        printf("\n&new: %p", &new);
        
        printf("\n\n*aux: %p", *aux);
        printf("\naux: %p", aux);
        printf("\n&aux: %p", &aux);
        
        new->value = num;
        new->next = NULL;

        printf("\n\nnew->value = num (%d)", num);
        printf("\nnew->next = NULL");


        if(isVoid(f)){
            printf("\n\nisVoid(f) ?");

            printf("\n*f: %p", *f);
            printf("\nf: %p", f);
            printf("\n&f: %p", &f);

            printf("\n\n*new: %d", *new);
            printf("\nnew: %p", new);
            printf("\n&new: %p", &new);

            printf("\n\n*aux: %p", *aux);
            printf("\naux: %p", aux);
            printf("\n&aux: %p", &aux);

            *f = new;

            printf("\n\n>> *f = new");
            printf("\nf continua apontando para a stack: %p", f);
            printf("\no conteUdo que antes era NULL passa a ser o endereco da struct: f->struct");

            printf("\n\n*f: %p", *f);
            printf("\nf: %p", f);
            printf("\n&f: %p", &f);

            printf("\n\n*new: %d", *new);
            printf("\nnew: %p", new);
            printf("\n&new: %p", &new);

            printf("\n\n*aux: %d", *aux);
            printf("\naux: %p", aux);
            printf("\n&aux: %p", &aux);

        } else {
            aux = *f;
            
            // Percorre a fila até o final
            while(aux->next){
                aux = aux->next;
            } 

            aux->next = new;
        }

    } else {
        printf("Erro de alocação");
    }
}

Node* removefila(Node **f){
    Node *remove = NULL;

    if(*f != NULL){
        remove = *f;
        *f = remove->next;
    } else {
        printf("Erro: fila vazia");
    }

    return remove;
}

int main(){

    Node *fila = NULL;
    
    printf("Node *fila = NULL");
    printf("\nfila: %p", fila);
    printf("\n&fila: %p\n", &fila);

    inserir(&fila, 2);

    return 0;
}