#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *right, *left;
} Node;

typedef struct {
    Node *root;
    int size;
} BinaryTree;

/* ====================== Versão de inserção 1 ======================

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

==================================================================*/

// Versão de Inserção 2
Node *insert_v2(Node *root, int value){
    
    // Árvore vazia
    if(root == NULL){
        Node *newNode = (Node*)malloc(sizeof(Node));
        
        newNode->value = value;
        newNode->left = NULL;
        newNode->right = NULL;

        return newNode;

    } else {
        if(value < root->value){
            root->left = insert_v2(root->left, value);
        }

        if(value > root->value){
            root->right = insert_v2(root->right, value);
        }

        return root;

    }
}

int getTreeSize(Node *root){
    if(root == NULL){
        return 0;
    } else {
        return 1 + getTreeSize(root->left) + getTreeSize(root->right);
    }
}

int search(Node *root, int key){
    if(root == NULL){
        return 0;
    } else {
        if(root->value == key){
            //return key;
            return 1;
        } else {
            if(key < root->value) {
                return search(root->left, key);
            } else if (key >= root->right){
                return search(root->right, key);
            }
        }
    }
}

// REMOVE CASE 1 : Remoção de nó-folha
Node* remover(Node *root, int key){
    if(root == NULL){
        printf("Error: Value not found!\n");
        return NULL;
    } else {
        if(root->value == key){
            if(root->left == NULL && root->right == NULL){
                free(root);
                return NULL;
            }

            else {
                // remover nó que possua 2 filhos
                if(root->left != NULL && root->right != NULL){

                }

                // remover nó que possua apenas 1 filho
                else{
                    Node* aux;
                    if(root->left != NULL){
                        aux = root->left;
                    } else {
                        aux = root->right;
                    }
                    free(root);
                    return aux;
                }
            }

        } else{
            if(key < root->value) {
                root->left = remover(root->left, key);
            } else if (key > root->right){
                root->right = remover(root->right, key);
            }
            
            return root;
        }
    }
}

// REMOVE CASE 2: Remoção de nó que possua um filho


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
    //BinaryTree tree;
    //tree.root = NULL;

    Node *root = NULL;

    do{
        printf("\n0- exit\n1- insert\n2- print\n3- search\n4- remove\n=> ");
        scanf("%d", &ans);

        switch(ans){
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

    } while(ans != 0);

    return 0;
}