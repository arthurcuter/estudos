#include "pilha.h"

void constroi_pilha (int capacidade, t_pilha *p) {
    p->dados = (int *) malloc(sizeof(int) * capacidade);
    p->topo = 0;
}

int empilha (t_pilha *p, int i) {
    if(esta_cheia(p)) return FRACASSO;
    p->dados[p->topo] = i;
    p->topo++;
    return SUCESSO;
}

int desempilha (t_pilha *, int *i) {
    if (esta_vazia(p)) return FRACASSO;
    *i = p->dados[--p->topo];
    return SUCESSO;
}

int tamanho (t_pilha *p) {
    return p->topo;
}

int esta_vazia (t_pilha *p) {
    if p->topo == 0;
}

int esta_cheia (t_pilha *p) {
    return p->topo == p->capacidade;
};