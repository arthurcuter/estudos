#include "pilha.h"

void constroi_pilha (int capacidade, t_pilha *p) {
    p->dados = (int *) malloc(sizeof(int) * capacidade);
    p->topo = 0;
}
void empilha (int, t_pilha *);
int desempilha (t_pilha *);
int tamanho (t_pilha *);
int esta_vazia (t_pilha *);
int esta_cheia (t_pilha *);