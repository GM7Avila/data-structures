#include <stdio.h>
#include <string.h>
#define SIZE 256

typedef struct HuffmanNode {
    char character; 
    int frequency; 
    struct HuffmanNode* left;
    struct HuffmanNode* right;
    struct HuffmanNode* next;
} Node;

typedef struct linkedList {
    Node *begin;
    int size;
} List;

// --------------------- parte 1 : TABELA DE FREQUÊNCIA ---------------------
void initializeTable(unsigned int table_f[]){
    for(int i=0; i<SIZE; i++){
        table_f[i] = 0;
    }
}
void setFrequencyList(unsigned char phrase[], unsigned int table_f[]){
    int i = 0;
    
    while(phrase[i] != '\0'){
        char ch = phrase[i];
        table_f[ch]++;
        i++;
    }
}
void printFrequencyTable(unsigned int table_f[]){
    
    printf("\tTABELA DE FREQUÊNCIA\n");
    
    for(int i=0; i<SIZE;i++){

        if(table_f[i]!=0){
            printf("\ttabela[%d] = %u = %c\n",i, table_f[i], i);
        }
    }
}

// ------------------ parte 2 : LISTA ENCADEADA ORDENADA  ------------------
// table_f[i] -> valor de frequencia
// indice i -> caracter
// ordenar por frequencia 
// gerar a lista encadeada e alocar os nós

void initializeList(List* list){
    list->begin = NULL;
    list->size = 0;
}

// inserindo de forma ordenada
void insertByOrder(List* list, Node *node){
    Node *aux;
    // lista vazia
    if(list->begin==NULL){
        list->begin = node;
    } 
    // frequência menor que o inicio da lista
    else if(node->frequency < list->begin->frequency) {
        node->next = list->begin;
        list->begin = node;
    } 
    // não tem frequência menor (percorrer a lista)
    else {
        aux = list->begin;
        while(aux->next && aux->next->frequency <= node->frequency){
            aux = aux->next;
        } 
        node->next = aux->next;
        aux->next = node;
    }
    list->size++;
}

void createList(unsigned int table_f[], List *list){
    for(int i=0; i<SIZE; i++){
        if(table_f[i] > 0){
            Node *node = malloc(sizeof(Node));
            if(node){
                node->character = i;
                node->frequency = table_f[i];
                
                node->left = NULL;
                node->right = NULL;
                node->next = NULL;

                insertByOrder(list, node);
            } else{
                printf("\tcreateList() memory error\n");
                break;
            }
        }
    }
}

void printList(List *list){
    Node* aux = list->begin;
    printf("\tLINKED LIST: [SIZE %d]\n", list->size);
    while(aux){
        printf("\tChar: %c Frequency: %d\n", aux->character, aux->frequency);
        aux = aux->next;
    }
}

int main() {

    // unsigned 0 ~ 255
    unsigned char phrase[] = "Hello, my name is Guilherme Medeiros Avila!";
    unsigned int table_f[SIZE];
    List list;

    
    // --------------------- parte 1 : TABELA DE FREQUÊNCIA ---------------------
    initializeTable(table_f);
    setFrequencyList(phrase,table_f);
    printFrequencyTable(table_f);

    printf("\n\n");

    // ------------------ parte 2 : LISTA ENCADEADA ORDENADA  ------------------
    initializeList(&list);
    createList(table_f, &list);
    printList(&list);

    return 0;
}