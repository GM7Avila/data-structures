#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* right, * left;
} Node;

Node* insert_v2(Node* root, int value) {

    // Árvore vazia
    if (root == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));

        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;

        return newNode;

    }
    else {
        if (value < root->value) {
            root->left = insert_v2(root->left, value);
        }

        if (value > root->value) {
            root->right = insert_v2(root->right, value);
        }

        return root;

    }
}

int getTreeSize(Node* root) {
    if (root == NULL) {
        return 0;
    }
    else {
        return 1 + getTreeSize(root->left) + getTreeSize(root->right);
    }
}

int search(Node* root, int key) {
    if (root == NULL) {
        return 0;
    }
    else {
        if (root->value == key) {
            //return key;
            return 1;
        }
        else {
            if (key < root->value) {
                return search(root->left, key);
            }
            else if (key > root->value) {
                return search(root->right, key);
            }
        }
    }
}

/*
    Função para remover nós da Árvore binária
*/
Node* remover(Node* raiz, int chave) {
    if (raiz == NULL) {
        printf("Valor nao encontrado!\n");
        return NULL;
    }
    else { // procura o nó a remover
        if (raiz->value == chave) {
            // remover nós folhas (nós sem filhos)
            if (raiz->left == NULL && raiz->right == NULL) {
                free(raiz);
                printf("Elemento folha removido: %d !\n", chave);
                return NULL;
            }
            else {
                // remover nós que possuem 2 filhos
                if (raiz->left != NULL && raiz->right != NULL) {
                    Node* aux = raiz->left;
                    while (aux->right != NULL)
                        aux = aux->right;
                    raiz->value = aux->value;
                    aux->value = chave;
                    printf("Elemento trocado: %d !\n", chave);
                    raiz->left = remover(raiz->left, chave);
                    return raiz;
                }
                else {
                    // remover nós que possuem apenas 1 filho
                    Node* aux;
                    if (raiz->left != NULL)
                        aux = raiz->left;
                    else
                        aux = raiz->right;
                    free(raiz);
                    printf("Elemento com 1 filho removido: %d !\n", chave);
                    return aux;
                }
            }
        }
        else {
            if (chave < raiz->value)
                raiz->left = remover(raiz->left, chave);
            else
                raiz->right = remover(raiz->right, chave);
            return raiz;
        }
    }
}

// print em ordem
void printTree(Node* root) {
    if (root != NULL) {
        printTree(root->left);
        printf("%d ", root->value);
        printTree(root->right);
    }
}


int main() {
    int ans, value;
    //BinaryTree tree;
    //tree.root = NULL;

    Node* root = NULL;

    do {
        printf("\n0- exit\n1- insert\n2- print\n3- search\n4- remove\n=> ");
        scanf("%d", &ans);

        switch (ans) {
        case 0:
            printf("\nClosed...");
            break;
        case 1:
            printf("\nInsert a value: ");
            scanf("%d", &value);
            root = insert_v2(root, value);
            //insert(&tree, value);
            break;
        case 2:
            printf("\nPrinting Binary Tree:\n");
            printTree(root);
            printf("\nTree size: %d\n", getTreeSize(root));
            break;
        case 3:
            printf("\nInsert a value: ");
            scanf("%d", &value);
            printf("- Result: %d\n", search(root, value));
            break;
        case 4:
            printf("\nInsert a value: ");
            scanf("%d", &value);
            root = remover(root, value);
            break;
        default:
            printf("\nInvalid Value");
        }

    } while (ans != 0);

    return 0;
}
