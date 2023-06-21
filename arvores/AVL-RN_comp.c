#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define INSERCOES    4000000
#define BUSCAS       4000000
#define FAIXA_BUSCA 16000000

#define QTDE_TESTES 5

#define aleatorio() (rand()*rand())

typedef enum {rubro, negro} Cor;

struct noArvoreAVL {
	int chave;
	int balanco;
	struct noArvoreAVL *esq, *dir;
};
typedef struct noArvoreAVL *PtrArvoreAVL;

struct noArvoreRN {
	int chave;
	Cor cor;
	struct noArvoreRN *esq, *dir;
};
typedef struct noArvoreRN *PtrArvoreRN;

// No especial para representar os nos esternos da arvore rubro-negra
struct noArvoreRN noExterno = {0, negro, NULL, NULL};
PtrArvoreRN externo = &noExterno;

typedef struct {
	int altura, nos;
} DadosArvore;

PtrArvoreAVL criaNoAVL(int v) {
	PtrArvoreAVL p;
	p = malloc(sizeof(struct noArvoreAVL));
	if (p != NULL) {
		p->chave = v;
		p->balanco = 0;
		p->esq = p->dir = NULL;
	}
	return p;
}

PtrArvoreRN criaNoRN(int v) {
	PtrArvoreRN p;
	p = malloc(sizeof(struct noArvoreRN));
	if (p != NULL) {
		p->chave = v;
		p->cor = rubro;
		p->esq = p->dir = externo;
	}
	return p;
}

// Insercao ocorreu na subarvore esquerda
// A variavel h determina se houve alteracao na altura da arvore
void caso1(PtrArvoreAVL *p, int *h) {
	PtrArvoreAVL u, v;
	u = (*p)->esq;
	if (u->balanco == -1) { // esquerda > direita (caso 1.1)
		// Realiza rotacao direita
		(*p)->esq = u->dir;
		u->dir = *p;
		(*p)->balanco = 0;
		*p = u;
	}
	else { // direita > esquerda (caso 1.2)
		// Realiza rotacao dupla direita
		v = u->dir;
		u->dir = v->esq;
		v->esq = u;
		(*p)->esq = v->dir;
		v->dir = *p;
		if (v->balanco == -1)
			(*p)->balanco = 1;
		else
			(*p)->balanco = 0;
		if (v->balanco == 1)
			u->balanco = -1;
		else
			u->balanco = 0;
		*p = v;
	}
	(*p)->balanco = 0;
	*h = 0;
}

// Insercao ocorreu na subarvore direita
// A variavel h determina se houve alteracao na altura da arvore
void caso2(PtrArvoreAVL *p, int *h) {
	PtrArvoreAVL z, y;
	z = (*p)->dir;
	if (z->balanco == 1) { // direita > esquerda (caso 2.1)
		// Realiza rotacao esquerda
		(*p)->dir = z->esq;
		z->esq = *p;
		(*p)->balanco = 0;
		*p = z;
	}
	else { // esquerda > direita (caso 2.2)
		// Realiza rotacao dupla esquerda
		y = z->esq;
		z->esq = y->dir;
		y->dir = z;
		(*p)->dir = y->esq;
		y->esq = *p;
		if (y->balanco == 1)
			(*p)->balanco = -1;
		else
			(*p)->balanco = 0;
		if (y->balanco == -1)
			z->balanco = 1;
		else
			z->balanco = 0;
		*p = y;
	}
	(*p)->balanco = 0;
	*h = 0;
}

// Faz insercao em uma arvore AVL
// A variavel h determina se houve alteracao na altura da arvore
void insereAVL(PtrArvoreAVL *a, int valor, int *h) {
	if (*a == NULL) { // Insere o no
		*a = criaNoAVL(valor);
		*h = 1;
		return;
	}
	if (valor == (*a)->chave) { // Chave ja existe
		*h = 0;
		return; // Retorna sem inserir
	}
	if (valor < (*a)->chave) { // Inserir a esquerda
		insereAVL(&((*a)->esq), valor, h);
		if (*h) // Se houve alteracao na altura
			switch ((*a)->balanco) {
				case 1:
					(*a)->balanco = 0;
					*h = 0;
					break;
				case 0:
					(*a)->balanco = -1;
					break;
				case -1:
					caso1(a, h); // Rebalancear
			}
	}
	else { // // Inserir a direita
		insereAVL(&((*a)->dir), valor, h);
		if (*h) // Se houve alteracao na altura
			switch ((*a)->balanco) {
				case -1:
					(*a)->balanco = 0;
					*h = 0;
					break;
				case 0:
					(*a)->balanco = 1;
					break;
				case 1:
					caso2(a, h); // Rebalancear
			}
	}
}

// q -> no inserido
// v -> pai de q
// w -> avo de q
// r -> bisavo de q
// caso -> determina o caso a ser tratado pela chamadora
//    0 -> Fazer verificacao da rota
//    2 -> Ocorreu rotacao e a arvore esta equilibrada
void rota(PtrArvoreRN *a, PtrArvoreRN q, PtrArvoreRN v, PtrArvoreRN w, PtrArvoreRN r, int *caso) {
	PtrArvoreRN t, aux;
	*caso = 2; // Valor padrao de caso se houver rotacao
	if (v->cor == rubro) { // So precisa de tratamento se cor de v = rubro
		if (v == (w->esq)) // Faz t = irmao de v
			t = w->dir;
		else
			t = w->esq;
		if (t->cor == rubro) { // Caso 2.1
			v->cor = negro;
			w->cor = rubro;
			t->cor = negro;
			*caso = 0; // Verificar rota
		}
		else { // Caso 2.2
			if (q == v->esq)
				if (v == w->esq) { // Caso 2.2.1 (rotacao direita)
					aux = v; // Guarda a nova raiz
					v->cor = negro;
					w->cor = rubro;
					w->esq = v->dir;
					v->dir = w;
				}
				else { // Caso 2.2.2  (rotacao dupla esquerda)
					aux = q; // Guarda a nova raiz
					q->cor = negro;
					w->cor = rubro;
					w->dir = q->esq;
					v->esq = q->dir;
					q->esq = w;
					q->dir = v;
				}
			else // q eh filho direito de v
				if (v == w->dir) { // Caso 2.2.3 (rotacao esquerda)
					aux = v; // Guarda a nova raiz
					v->cor = negro;
					w->cor = rubro;
					w->dir = v->esq;
					v->esq = w;
				}
				else { // Caso 2.2.4 (rotacao dupla direita)
					aux = q; // Guarda nova raiz
					q->cor = negro;
					w->cor = rubro;
					w->esq = q->dir;
					v->dir = q->esq;
					q->esq = v;
					q->dir = w;
				}
			if (r == NULL) // Se a rotacao ocorreu na raiz
				*a = aux;
			else // Recoloca arvore balanceada no bisavo de q
				if (q->chave < r->chave)
					r->esq = aux;
				else
					r->dir = aux;
		}
	}
	(*a)->cor = negro; // A raiz da arvore sempre eh negra
}

// Faz insercao em uma arvore rubro-negra
// a -> raiz da arvore
// v -> no onde ocorrera a insercao
// w -> pai de v
// r -> avo de v
// valor -> chave a ser inserida na arvore
// caso -> determina o caso tratado por rota() ou retorno de recursividade
//    0 -> Insercao pelo caso 2.1. Verificar rota ate a raiz.
//    1 -> Verificar rota ate a raiz.
//    2 -> Houve rotacao. A arvore esta equilibrada
void insereRN(PtrArvoreRN *a, PtrArvoreRN *v, PtrArvoreRN w, PtrArvoreRN r, int valor, int *caso) {
	PtrArvoreRN q, raiz;
	raiz = *a;
	if (*v == externo) { // Novo no sera inserido nesse ponto
		*v = criaNoRN(valor);
		if (raiz == externo) { // Primeiro no da arvore
			(*v)->cor = negro;
			*a = *v;
		}
		else
			if (valor < w->chave) // v eh filho esquerdo de w
				w->esq = *v;
			else // v eh filho direito de w
				w->dir = *v;
	}
	else // Descer mais na arvore para encontrar ponto de insercao
		if (valor != (*v)->chave) { // Se foi encontrada a chave a ser inserida nao faz nada
			if (valor < (*v)->chave) // Desce pela esquerda
				q = (*v)->esq;
			else // Desce pela direita
				q = (*v)->dir;
			insereRN(a, &q, *v, w, valor, caso);
			if (*caso == 1) // Ainda nao passou pela funcao rota()
				rota(a, q, *v, w, r, caso);
			else
				if (*caso == 0) // Passou por rota() mas ainda precisa verificar ancestrais
					*caso = 1;
		}
}

PtrArvoreAVL buscaAVL(PtrArvoreAVL a, int valor) {
	while (a != NULL) {
		if (valor == a->chave)
			return a;
		if (valor < a->chave)
			a = a->esq;
		else
			a = a->dir;
	}
	return NULL;
}

PtrArvoreRN buscaRN(PtrArvoreRN a, int valor) {
	while (a != externo) {
		if (valor == a->chave)
			return a;
		if (valor < a->chave)
			a = a->esq;
		else
			a = a->dir;
	}
	return NULL;
}

void liberaNosAVL(PtrArvoreAVL *a) {
	if (*a != NULL) {
		liberaNosAVL(&((*a)->esq));
		liberaNosAVL(&((*a)->dir));
		free(*a);
	}
}

void liberaNosRN(PtrArvoreRN *a) {
	if (*a != externo) {
		liberaNosRN(&((*a)->esq));
		liberaNosRN(&((*a)->dir));
		free(*a);
	}
}

DadosArvore dadosAVL(PtrArvoreAVL a) {
	DadosArvore d1, d2;
	if (a == NULL) {
		d1.altura = -1;
		d1.nos = 0;
	}
	else {
		d1 = dadosAVL(a->esq);
		d2 = dadosAVL(a->dir);
		if (d1.altura < d2.altura)
			d1.altura = d2.altura;
		d1.altura++;
		d1.nos += d2.nos + 1;
	}
	return d1;
}

DadosArvore dadosRN(PtrArvoreRN a) {
	DadosArvore d1, d2;
	if (a == externo) {
		d1.altura = -1;
		d1.nos = 0;
	}
	else {
		d1 = dadosRN(a->esq);
		d2 = dadosRN(a->dir);
		if (d1.altura < d2.altura)
			d1.altura = d2.altura;
		d1.altura++;
		d1.nos += d2.nos + 1;
	}
	return d1;
}

int main(void) {
	PtrArvoreAVL aAVL;
	PtrArvoreRN aRN;
	int i, teste, h, caso;
	struct timeval t1, t2;
	double tempo, tempoInsAVL, tempoInsRN, tempoBuscaAVL, tempoBuscaRN;
	int alturaAVL, alturaRN;
	DadosArvore d;

	srand(time(NULL));
	tempoInsAVL = tempoInsRN = tempoBuscaAVL = tempoBuscaRN = 0;
	alturaAVL = alturaRN = 0;
	for (teste=1; teste<=QTDE_TESTES; teste++) {
		printf("###########################\n");
		printf("## SEQUENCIA DE TESTE %02d ##\n", teste);
		printf("###########################\n\n");
		aAVL = NULL;
		printf("Inserindo %d chaves aleatorias na arvore AVL.\n", INSERCOES);
		gettimeofday(&t1, NULL);
		for (i=0; i<INSERCOES; i++)
			insereAVL(&aAVL, aleatorio()%FAIXA_BUSCA, &h);
		gettimeofday(&t2, NULL);
		tempoInsAVL += tempo = (double) t2.tv_sec - t1.tv_sec + (t2.tv_usec - t1.tv_usec)/1000000.0;
		printf("Tempo das insercoes: %lf segundos.\n", tempo);
		d = dadosAVL(aAVL);
		alturaAVL += d.altura;
		printf("Altura da arvore gerada: %d\n", d.altura);
		printf("Quantidade de nos inseridos: %d\n", d.nos);
		printf("Buscando %d chaves aleatorias na arvore AVL.\n", BUSCAS);
		gettimeofday(&t1, NULL);
		for (i=0; i<BUSCAS; i++)
			buscaAVL(aAVL, aleatorio()%FAIXA_BUSCA);
		gettimeofday(&t2, NULL);
		tempoBuscaAVL += tempo = (double) t2.tv_sec - t1.tv_sec + (t2.tv_usec - t1.tv_usec)/1000000.0;
		printf("Tempo das buscas: %lf segundos.\n\n", tempo);
		liberaNosAVL(&aAVL);
		
		aRN = externo;
		printf("Inserindo %d chaves aleatorias na arvore rubro-negra.\n", INSERCOES);
		gettimeofday(&t1, NULL);
		for (i=0; i<INSERCOES; i++) {
			caso = 1;
			insereRN(&aRN, &aRN, NULL, NULL, aleatorio()%FAIXA_BUSCA, &caso);
		}
		gettimeofday(&t2, NULL);
		tempoInsRN += tempo = (double) t2.tv_sec - t1.tv_sec + (t2.tv_usec - t1.tv_usec)/1000000.0;
		printf("Tempo das insercoes: %lf segundos.\n", tempo);
		d = dadosRN(aRN);
		alturaRN += d.altura;
		printf("Altura da arvore gerada: %d\n", d.altura);
		printf("Quantidade de nos inseridos: %d\n", d.nos);
		printf("Buscando %d chaves aleatorias na arvore rubro-negra.\n", BUSCAS);
		gettimeofday(&t1, NULL);
		for (i=0; i<BUSCAS; i++)
			buscaRN(aRN, aleatorio()%FAIXA_BUSCA);
		gettimeofday(&t2, NULL);
		tempoBuscaRN += tempo = (double) t2.tv_sec - t1.tv_sec + (t2.tv_usec - t1.tv_usec)/1000000.0;
		printf("Tempo das buscas: %lf segundos.\n", tempo);
		liberaNosRN(&aRN);
		printf("\n");
	}
	printf("################\n");
	printf("## RESULTADOS ##\n");
	printf("################\n\n");
	printf("Tempo medio das insercoes na arvore AVL: %lf segundos.\n", tempoInsAVL/QTDE_TESTES);
	printf("Tempo medio das buscas na arvore AVL: %lf segundos.\n", tempoBuscaAVL/QTDE_TESTES);
	printf("Altura media da arvore AVL: %.2f\n", (float) alturaAVL/QTDE_TESTES);
	printf("Tempo medio das insercoes na arvore rubro-negra: %lf segundos.\n", tempoInsRN/QTDE_TESTES);
	printf("Tempo medio das buscas na arvore rubro-negra: %lf segundos.\n", tempoBuscaRN/QTDE_TESTES);
	printf("Altura media da arvore rubro-negra: %.2f\n", (float) alturaRN/QTDE_TESTES);
	return 0;
}