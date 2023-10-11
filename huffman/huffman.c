#include <stdio.h>
#include <string.h>

#define TAM 256

// Huffman Node
struct HuffmanNode {
    char character; 
    int frequency; 
    struct HuffmanNode* left;
    struct HuffmanNode* right;
    struct HuffmanNode* next;
} huffmanNode;


// --------------------- parte 1 : TABELA DE FREQUÊNCIA ---------------------
void zero_initialize(unsigned int list_f[]){
    for(int i=0; i<TAM; i++){
        list_f[i] = 0;
    }
}
void setFrequencyList(unsigned char phrase[], unsigned int list_f[]){
    int i = 0;
    
    while(phrase[i] != '\0'){
        char ch = phrase[i];
        list_f[ch]++;
        i++;
    }
}
void printFrequencyList(unsigned int list_f[]){
    
    printf("\tTABELA DE FREQUÊNCIA");
    
    for(int i=0; i<TAM;i++){

        if(list_f[i]!=0){
            printf("tabela[%d] = %d = %c\n",i, list_f[i], i);
        }
    }
}



int main() {

    // unsigned 0 ~ 255
    unsigned char phrase[] = "Vamos aprender a programar";
    unsigned int list_f[TAM];
    
    // --------------------- parte 1 : TABELA DE FREQUÊNCIA ---------------------
    zero_initialize(list_f);
    setFrequencyList(phrase,list_f);
    printFrequencyList(list_f);

    return 0;
}