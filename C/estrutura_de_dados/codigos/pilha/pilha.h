#include <stdlib.h>
#include <stdio.h>

#define SUCESSO 1
#define FRACASSO 0

typedef struct {
    int * dados;
    int topo;
    int capacidade;
} t_pilha;

void constroi_pilha (int, t_pilha *);

int empilha (t_pilha *, int);
// retorno SUCESSO ou FRACASSO
// parâmetros: a pilha por referência (pode ser alterada) e
// o inteiro de entrada

int desempilha (t_pilha *, int *);
// retorno SUCESSO ou FRACASSO
// parâmetros: a pilha por referência (pode ser alterada) e
// o inteiro por referência (pode receber o valor que vai sair da pilha)

int tamanho (t_pilha *);

int esta_vazia (t_pilha *);

int esta_cheia (t_pilha *);

void exibe_pilha(t_pilha *);

int extrai_elemento(t_pilha *);

int valor_topo(t_pilha *);

void amassa_topo (t_pilha *, int);

void amassa_pilha(t_pilha *, int );

int sobrecarrega_pilha(t_pilha *, int );

int esta_cheia2 (t_pilha *);

int empilha2 (t_pilha *, int);