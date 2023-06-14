#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *right, *left;
} Node;

typedef struct {
    Node *root;
} BinaryTree;


void insertLeft(Node *node, int value){
    if(node->left == NULL){
        Node *newNode = (Node*)malloc(sizeof(Node));

        if (newNode == NULL) {
            printf("Erro: falha na alocação de memória.\n");
            exit(1);
        }        

        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;

        node->left = newNode;

    } else {
        if(value < node->left->value)
            insertLeft(node->left, value);
        if(value > node->left->value)
            insertRight(node->left, value);
    }
}

void insertRight(Node *node, int value){
    if(node->right == NULL){ 
        Node *newNode = (Node*)malloc(sizeof(Node));

        if (newNode == NULL) {
            printf("Erro: falha na alocação de memória.\n");
            exit(1);
        }

        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;

        node->right = newNode;

    } else {
        if(value > node->right->value)
            insertRight(node->right, value);
        if(value < node->right->value)
            insertLeft(node->right, value);
    }
}

void insert(BinaryTree *tree, int value){

    // Verificando se a Árvore está vazia
    if(tree->root == NULL){
        Node *newNode = (Node*)malloc(sizeof(Node));
        
        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;

        tree->root = newNode;

    } else {

        if(value < tree->root->value)
            insertLeft(tree->root, value);
        if(value > tree->root->value)
            insertRight(tree->root, value);
        
    }


}

// print em ordem
void printTree(Node *root){
    if(root != NULL){
        printTree(root->left);
        printf("%d ", root->value);
        printTree(root->right);
    }
}


int main(){
    int ans, value;
    BinaryTree tree;
    tree.root = NULL;

    do{
        printf("\n0- exit\n1- insert\n2- print\n=> ");
        scanf("%d", &ans);

        switch(ans){
            case 0:
                printf("\nClosed...");
                break;
            case 1:
                printf("\nInsert a value: ");
                scanf("%d", &value);

                insert(&tree, value);
                break;
            case 2:
                printf("\nPrinting Binary Tree:\n");
                printTree(tree.root);
                break;
            default:
                printf("\nInvalid Value");

        }

    } while(ans != 0);

    return 0;
}