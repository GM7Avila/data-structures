#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

/*

ESTRUTURA DE DADOS: IMPLEMENTAÇÃO DE GRAFO NÃO DIRIGIDO

O esquema (visual) da estrutura do grafo pode ser encontrado neste repositório, no arquivo: 

`undirected-graph0adjaceny-list.png`; 

*/ 

// Definição da estrutura por Lista de Adjacência
struct graph {
    int is_weighted;  /* 0: False; 1: True*/
    int num_vertices; /* Numero de vértices conectados ao Grafo - definido na criação */
    int max_degree;   /* Numero máximo - limite - de grau para cada vértice */
    int *degree;      /* Grau do vértice*/
    int **edges;      /* Ponteiro para as arestas do grafo */
    float** weights;  /* Ponteiro para os valores dos pesos - para grafos ponderados */
};

// Função de criação do grafo com parâmetros iniciais
Graph* init_graph(int is_weighted, int num_vertices, int max_degree){
    
    Graph *grafo;
    grafo = (Graph*) malloc(sizeof(struct graph));

    if(grafo == NULL){
        printf("Erro: unable to allocate memory for the graph");
        exit(EXIT_FAILURE);
    }

    if(grafo != NULL){

        grafo->is_weighted = is_weighted;
        grafo->num_vertices = num_vertices;
        grafo->max_degree = max_degree;

        // Alocando um vetor para os graus do grafo
        grafo->degree = (int *)malloc(num_vertices * sizeof(int));

        if(grafo->degree == NULL){
            printf("Erro: unable to allocate memory for the graph degrees");
            exit(EXIT_FAILURE);
        } else{

            // Inicializando todos os graus com zero
            for(int i=0; i < num_vertices; i++){
                grafo->degree[i] = 0;
            }
        }

        // Alocando arestas
        // edges aponta para uma lista de ajacência de int
        grafo->edges = (int **) malloc(num_vertices * sizeof(int*));
        for(int i=0; i<num_vertices; i++){
            grafo->edges[i] = (int*) malloc(max_degree * sizeof(int));
        }

        // Caso o grafo seja ponderado
        if(grafo->is_weighted == 1){
            // weights aponta para uma lista de ajacência de floats
            grafo->weights = (float**) malloc(num_vertices * sizeof(float*));
            for(int i=0; i<num_vertices; i++){
                grafo->weights[i] = (float*) malloc(max_degree * sizeof(float));
            }
        }
    }

    return grafo;

}

int main(){
    Graph *g;
    g = init_graph(0,5,8);
    
    return 0;
}