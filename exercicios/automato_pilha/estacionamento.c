#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <string.h>

#define MAX_SIZE 5
#define N 9

// carro - registro + count manobras
typedef struct {
    char registro[9]; // [E/S] AAA1111
    int count;
} Car;

// pilha de Carros - carro + posição do topo 
typedef struct {
    Car garage[MAX_SIZE];
    int top;
} Stack;

// apaga uma vaga (torna ela "vazia" - carro com informações "null") - Recebe um ponteiro para a pilha e o index da vaga que deseja "apagar" o elemento
void makeVoid(Stack *p, int i){

    strcpy (p->garage[i].registro, "Vazio");
    p->garage[i].count = 0;

}

// inicializa vazio
void stackStarter (Stack *p) {
   
    p->top = 0;

    for(int i=0; i<MAX_SIZE; i++){
        
        Car voidCar;
        voidCar.count = 0;
        p->garage[i] = voidCar;

        makeVoid(p, i);
    }

}

// printa a pilha
void printStack(Stack *p, bool isAux){
    
    printf("\n");

    if (isAux == true){
        printf("======= AUXILIAR =======\n");
    } else printf("==== ESTACIONAMENTO ====\n");

    for(int i=0; i<MAX_SIZE; i++){

        int resultCmp = strcmp(p->garage[i].registro, "Vazio");

        if(resultCmp == 0){
            printf("Vaga %d: [%s]\n", i+1, p->garage[i].registro);
        } else {
            printf("Vaga %d: [%s | x%d]\n", i+1, p->garage[i].registro, p->garage[i].count);
        }
    }

    printf("========================\n");

}

void comandLine(Stack *p, Stack *aux, char *comands[], int n){

    // roda a lista de comandos
    for(int i=0; i < n; i++){
        
        int index_markdown = 0; 

        // FUNC. DE ENTRADA - PRIMEIRA VEZ DO CARRO NA PILHA
        if(comands[i][0] == 'E'){

            // Se a pilha estiver cheia: stack overflow
            if(p->top >= MAX_SIZE){
                printf("\nStack overflow: (%s) Nao ha mais vagas", comands[i]);
            } else {

            // Criar um struct Car e transferir os dados da lista de comando para um carro estacioando no topo
            Car newCar;
            strcpy(newCar.registro, comands[i]);
            newCar.count = 0; 

            printf("\n[E] Carro %s vai entrar no estacionamento", newCar.registro);

            // Aloca o carro na pilha p, e soma o topo para que o prox. carro seja alocado na última vaga disponível
            p->garage[p->top] = newCar;
            p->top++;

            }

        } else if (comands[i][0] == 'S'){
            // busca a posição pela placa na pilha p
            for(int j=0; j < p->top; j++){ 
                // compara a partir do primeiro elemento = Número da placa AAA1111
                if(strcmp(&(p->garage[j].registro)[1], &(comands[i])[1]) == 0){
                    index_markdown = j; //index da onde vai começar o loop de remoção

                    // transferência de dados do vetor p (estacionamento) para o aux (auxiliar)
                    for(int x=index_markdown; x < p->top; x++){
                        // contabiliza uma manobra de saída do veículo
                        p->garage[x].count++;
                        
                        printf("\n[S] Carro %s vair sair do estacionamento", p->garage[x].registro);

                        // transfere os elementos de p para aux e incrementa o topo em aux
                        aux->garage[aux->top] = p->garage[x]; 
                        aux->top++;
                        makeVoid(p, x);
                        
                        printf("\n");
                        printStack(p, false);
                        printStack(aux, true);

                    }

                    //p->top -= temp_pTop;
                    p->top = index_markdown;

                    // voltando com os valores de aux para p na posição index_markdown
                    // i = 1 - aux[0] é o carro que está sendo retirado, func. de saida
                    makeVoid(aux, 0);
                    
                    for(int i = 1; i < aux->top; i++){

                        printf("\n- Carro %s vai manobrar de volta ao estacionamento. Manobras: x%d", aux->garage[i].registro, aux->garage[i].count);

                        p->garage[p->top] = aux->garage[i]; 
                        p->top ++;

                        makeVoid(aux, i);
                        
                    } 
                    printf("\n");
                    aux->top = 0;

                    printStack(p, false);
                    printStack(aux, true);
                } else {
                    printf("\nO carro %s ainda nao esta no estacionamento\n", &(comands[i][2]));
                }
            } 
        } 
    }
}
// TO-DO : criar métodos para cada função acima

int main(){

    Stack p; // pilha -> alameda
    Stack aux; // pilha auxiliar -> para manobrar
    
    // Comand Line: Carros entrando
    char *StringList[N]={
        "E KVN4546", 
        "E BAF3597", 
        "E TCP8080", 
        "E JAV4123", 
        "E SAF7770",
        "S BAF3597",
        "E NEW0000", 
        "E NAO1013",
        "S JAV4123"
    };

    // Iniciando a pilha vazia  
    stackStarter(&p);
    stackStarter(&aux);

    // print vazio
    printStack(&p, false);
    printStack(&aux, true);
    
    comandLine(&p, &aux, StringList, N);
    
    printf("\n\nResultado");
    printStack(&p, false);
    printStack(&aux, true);

    return 1;

}