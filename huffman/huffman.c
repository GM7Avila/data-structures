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

// ---------------- parte 3 : MONTANDO A ÁRVORE DE HUFFMAN  ----------------
// - Remover os dois nós com menor frequência

Node *removeNodeFromList(List *list){
    Node *aux = NULL;

    // checar se a Lista não esta vazia para remover
    if(list->begin){
        aux = list->begin;
        list->begin = aux->next;
        aux->next = NULL;
        list->size--;
    }

    return aux;
}

Node * assembleHuffmanTree(List *list){
    
    Node *first, *second, *new;

    // remover de dois em dois
    while(list->size > 1){
        // removendo o primeiro nó
        first = removeNodeFromList(list);
        // removendo o segundo nó
        second = removeNodeFromList(list);

        // novo nó (pai)
        new = malloc(sizeof(Node));
        if(new){
            new->character = '+';
            new->frequency = first->frequency + second->frequency;
            new->left = first;
            new->right = second;
            new->next = NULL;

            // por fim inserir novamente na lista
            insertByOrder(list, new);

        } else {
            printf("\tassembleHuffmanTree() memory error\n");
            //return NULL;
            break;
        }
    }

    // retorna a raiz
    return list->begin;

}

void printTree(Node *root, int size){
    // se for um nó folha
    if(root->left == NULL && root->right == NULL){
        printf("\tLeaf: %c\tHeight: %d\n", root->character, size);
    } else{
        printTree(root->left, size++);
        printTree(root->right, size++);
    }
}

// -------------------- parte 4 : MONTANDO O DICIONÁRIO --------------------
// - O dicionário será uma matriz de strings
// - Quantidade de linhas: tamanho da tabela ASCII
// - Quantidade de colunas: altura da árvore de huffman (caminhos possíveis)
//      - implementar a altura da arvore

int getHeight(Node *root){
    int left, right;
    
    if(root == NULL){
        return -1;
    } else{
        getHeight(root->left) + 1;
        getHeight(root->right) + 1;
        
        if(left>right)
            return left;
        else 
            return right;
    }
}

// alocando memória para o dicionário
char **allocDictionary(int columns){
    char **dictionary;

    // Fazendo a alocação dinâmica da matriz 
    dictionary = malloc(SIZE * sizeof(char*));
    for(int i=0; i<SIZE; i++){
        // calloc limpa a memória
        dictionary[i] = calloc(columns, sizeof(char));
    }

    return dictionary;

}

// Gerando o dicionário
// - stringcode = caminho que gera o código binario em string e substitui o ASCII 
// - no inicio o stringcode é vazio
void createDictionary(char **dictionary, Node *root, char *string_code, int columns){
    
    // 1. se estiver em um nó folha, acessa a linha do dicionario e salva o string_code 
    // 2. se não for um nó folha (montagem do caminho): copia para os auxiliares esquerda e direita.
    // 3. esquerda - concatenar 0; direita - concatenar 1
    // 4. salva a string_code na linha do dicionario
    
    // precisam ter no minimo o tamanho das colunas
    char left[columns], right[columns];

    // no folha
    if(root->left == NULL & root->right == NULL){
        strcpy(dictionary[root->character], string_code);
    } 
    // no intermediario, percorrer a esquerda e direita
    else{
        strcpy(left, string_code);
        strcpy(right, string_code);

        // 0 para esquerda, e 1 para direita
        strcat(left, "0");
        strcat(right, "1");

        createDictionary(dictionary, root->left, left, columns);
        createDictionary(dictionary, root->right, right, columns);
    }
}

void printDictionary(char** dictionary){

    printf("\n\tDICTIONARY:\n");

    for(int i=0; i<SIZE; i++){
        if(strlen(dictionary[i]) > 0){
            printf("\tASCII [%3d]\tCode[%s]\n", i, dictionary[i]);
        }
    }
}

int main() {

    // unsigned 0 ~ 255
    unsigned char phrase[] = "Hello, my name is Guilherme Medeiros Avila!";
    unsigned int table_f[SIZE];
    List list;
    Node *huffmanTree;
    int columns;
    char **dictionary;

    
    // --------------------- parte 1 : TABELA DE FREQUÊNCIA ---------------------
    initializeTable(table_f);
    setFrequencyList(phrase,table_f);
    printFrequencyTable(table_f);

    printf("\n\n");

    // ------------------ parte 2 : LISTA ENCADEADA ORDENADA  ------------------
    initializeList(&list);
    createList(table_f, &list);
    printList(&list);

    printf("\n");

    // ---------------- parte 3 : MONTANDO A ÁRVORE DE HUFFMAN  ----------------
    huffmanTree = assembleHuffmanTree(&list);
    printf("\n\tHUFFMAN TREE\n");
    printTree(huffmanTree, 0);

    // -------------------- parte 4 : MONTANDO O DICIONÁRIO --------------------
    columns = getHeight(huffmanTree) + 1;
    dictionary = allocDictionary(columns);
    createDictionary(dictionary, huffmanTree, "", columns);
    printDictionary(dictionary);

    return 0;
}