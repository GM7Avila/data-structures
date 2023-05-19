#include <stdio.h>
#include <stdlib.h>

void desaloca_vetor1(int *newV){

    // cria uma variável na stack newV (não tem relação com v)
    // newV aponta para o mesmo lugar que v

    printf("\n\n=====> func desaloca_vetor(int *newV)");

    printf("\n    &newV = %p", &newV);
    printf("\n    newV = %p", newV);
    printf("\n    *newV = Heap[0] = %d", *newV);

    // free (endereço) - desaloca a região que aponta
    free(newV);

    // newV (variavel local) = null; porém v continua apontando para região desalocada
    newV = NULL;

    printf("\n\n    free(newV) & newV = NULL");
    printf("\n    &newV = %p", &newV);
    printf("\n    newV = %p - ATERRAMENTO (NULL)", newV); // 00000 = NULL - Aterramento
    // printf("\n*newV = Heap[0] = %d", *newV);

}



// desaloca_vetor2 recebe o endereco de a
// o endereco de a é de um ponteiro de inteiro
// entao o parametro deve ser um ponteiro de ponteiro de inteiro
// assim a variavel newA é um ponteiro que aponta para o ponteiro de inteiro a

//   desaloca_vetor2(    &a    )
void desaloca_vetor2(int **newA){
    
    // &newA = endereço na stack de newA (ponteiro) 
    // newA = endereço do local para onde newA aponta: newA -> a
    // *newA = conteudo de a = endereço da heap[0]
    // **newA = conteudo do endereço da heap[0] = valor inteiro (0)

    printf("\n\n=====> func desaloca_vetor(int **newA)");
    printf("\n    &newA = %p", &newA);
    printf("\n    newA = %p", newA);
    printf("\n    *newA = %p", *newA);
    printf("\n    **newA = Heap[0] = %d", **newA);

    /*  ATENCAO! 
    
    'free(newA)' resultaria em um erro, pois 'newA' aponta para a variavel 'a', entretando 'a' está localizada na memória stack, e 'free()' é dinâmico. 

    o correto, é utilizar 'free()' para o endereco na memoria heap. Portanto, iremos utilizar 'free(**newA)' - conteudo do conteudo de onde newA aponta (*a) = heap[0] - para operar diretamente a heap;
    
    */

   // free(**newA) -> erro: desalocando um valor inteiro! 
   free(*newA); //ou free(*newA)
   *newA = NULL;

}

int main(){
    printf("FUNC. P/ DESALOCAR VETOR DINAMICO & NOTES\n");
    
    printf("\nCaso 1) Problema ao desalocar v:\n");
    int *v = (int*) calloc(3, sizeof(int)); 

    printf("\n&v = %p", &v); // endereço do vetor v na stack
    printf("\nv = %p", v); // endereço para qual v aponta (heap)
    printf("\n*v = Heap[0] = %d", *v); // conteúdo do endereço para qual v aponta (*heap[0])

    // chama a função de desalocar vetor
    desaloca_vetor1(v);

    printf("\n\n=====> depois da func desaloca_vetor(v)");
    printf("\n&v = %p", &v); // endereço do vetor v na stack
    printf("\nv = %p", v); // endereço para qual v aponta (heap)
    printf("\n*v = Heap[0] = %d", *v); // conteúdo do endereço para qual v aponta (*heap[0])

    printf("\n\n====> NOTAS");
    printf("\n- v continua apontando para o mesmo local que apontava antes");
    printf("\n- regiao na memoria para qual v apontava (*v) = NULL (garbage)");

    // newV foi aterrado, e ao fim da func. foi desalocado da memoria
    // no entato, o ideal é que v aponte para NULL



    printf("\n\nCaso 2) Forma correta de desalocar:\n");
    int *a = (int*) calloc(3, sizeof(int));

    printf("\n&a = %p", &a); 
    printf("\na = %p", a); 
    printf("\n*a = Heap[0] = %d", *a); 

    desaloca_vetor2(&a);

    printf("\n\n=====> depois da func desaloca_vetor(a)");
    printf("\n&a = %p", &a); // endereço do vetor v na stack
    printf("\na = %p", a); // endereço para qual v aponta (heap)
    printf("\n*a = Heap[0] = %d", *a); // conteúdo do endereço para qual v aponta (*heap[0])

}