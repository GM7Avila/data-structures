#include <stdio.h>

// Definição da estrutura por Lista de Adjacência
struct graph {
    int is_weighted;  /* 0: False; 1: True*/
    int num_vertices; /* Numero de vértices conectados ao Grafo - definido na criação */
    int max_degree;   /* Numero máximo - limite - de grau para cada vértice */
    int *degree;      /* Grau do vértice*/
    int **edges;      /* Ponteiro para as arestas do grafo */
    float** weights;  /* Ponteiro para os valores dos pesos - para grafos ponderados */
}

