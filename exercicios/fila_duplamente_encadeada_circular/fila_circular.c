#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *prev;
    struct node *next;
} Node;

void enfileira(Node **fila, int i) {
    Node *newNode = malloc(sizeof(Node));
    newNode->value = i;

    if (*fila == NULL) {
        *fila = newNode;
        newNode->prev = newNode;
        newNode->next = newNode;
    } else {
        newNode->prev = (*fila)->prev;
        newNode->next = *fila;
        (*fila)->prev->next = newNode;
        (*fila)->prev = newNode;
    }
}

int desenfileira(Node **fila) {
    if (*fila == NULL) {
        printf("Erro: fila vazia\n");
        exit(1);
    }

    Node *removed = *fila;
    int value = removed->value;

    if (removed->next == removed) {
        *fila = NULL;
    } else {
        removed->prev->next = removed->next;
        removed->next->prev = removed->prev;
        *fila = removed->next;
    }

    free(removed);
    return value;
}

int vazia(Node *fila) {
    return (fila == NULL);
}

void mostra(Node *fila) {
    if (fila == NULL) {
        printf("Fila vazia\n");
        return;
    }

    Node *current = fila;
    do {
        printf("%d ", current->value);
        current = current->next;
    } while (current != fila);

    printf("\n");
}

void mostraInverso(Node *fila) {
    if (fila == NULL) {
        printf("Fila vazia\n");
        return;
    }

    Node *last = fila->prev;
    Node *current = last;

    do {
        printf("%d ", current->value);
        current = current->prev;
    } while (current != last);

    printf("\n");
}

int main() {
    Node *fila = NULL;

    enfileira(&fila, 1);
    enfileira(&fila, 2);
    enfileira(&fila, 3);
    enfileira(&fila, 4);
    enfileira(&fila, 5);

    mostra(fila);

    int valorRemovido = desenfileira(&fila);
    printf("Valor removido: %d\n", valorRemovido);
    mostra(fila);

    mostraInverso(fila);


    return 0;
}
