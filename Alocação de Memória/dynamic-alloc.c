#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void printVector(int *vetor, int size, const char *tipo) {
    printf("Vetor %s:\n", tipo);
    for (int i = 0; i < size; i++) {
        printf("[%d] = %d (%p)\n", i, vetor[i], (void*)&vetor[i]);
    }
    printf("\n");
}

void desalocarVetor(int *vetor) {
    free(vetor);
    vetor = NULL;
}

int main() {
    // Alocação Estática
    int vetorEstatico[SIZE] = {1, 2, 3, 4, 5};

    // Alocação Dinâmica 
    int *vetorMalloc = (int *)malloc(SIZE * sizeof(int));
    if (vetorMalloc == NULL) {
        printf("Erro ao alocar memória para vetorMalloc.\n");
        exit(EXIT_FAILURE);
        return 1;
    }

    int *vetorCalloc = (int *)calloc(SIZE, sizeof(int));
    if (vetorCalloc == NULL) {
        printf("Erro ao alocar memória para vetorCalloc.\n");
        exit(EXIT_FAILURE);
        return 1;
    }

    for (int i = 0; i < SIZE; i++) {
        vetorMalloc[i] = i + 1;
        vetorCalloc[i] = i + 1;
    }

    printVector(vetorEstatico, SIZE, "Estático");
    printVector(vetorMalloc, SIZE, "Dinâmico (malloc)");
    printVector(vetorCalloc, SIZE, "Dinâmico (calloc)");

    // Desalocando vetores dinâmicos
    desalocarVetor(vetorMalloc);
    desalocarVetor(vetorCalloc);

    return 0;
}
