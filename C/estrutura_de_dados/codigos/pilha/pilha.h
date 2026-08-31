#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int * dados;
    int topo;
} t_pilha;
void constroi_pilha (int, t_pilha *);
void empilha (int, t_pilha *);
int desempilha (t_pilha *);
int tamanho (t_pilha *);
int esta_vazia (t_pilha *);
int esta_cheia (t_pilha *);
