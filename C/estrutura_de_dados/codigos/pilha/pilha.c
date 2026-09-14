#include "pilha.h"

void constroi_pilha (int capacidade, t_pilha *p) {
    p->dados = (int *) malloc(sizeof(int) * capacidade);
    p->topo = 0;
    p->capacidade = capacidade;
}

int empilha (t_pilha *p, int i) {
    if(esta_cheia(p)) return FRACASSO;
    p->dados[p->topo] = i;
    p->topo++;
    return SUCESSO;
}

int desempilha (t_pilha *p, int *i) {
    if (esta_vazia(p)) return FRACASSO;
    *i = p->dados[--p->topo];
    return SUCESSO;
}

int tamanho (t_pilha *p) {
    return p->topo;
}

int esta_vazia (t_pilha *p) {
    return p->topo == 0;
}

int esta_cheia (t_pilha *p) {
    return p->topo == p->capacidade;
};

void exibe_pilha(t_pilha *p) {
    int i = p->topo - 1;
    while(i > -1) {
        printf("Elemento %d da pilha: %d\n", i, p->dados[i]);
        i--;
    }
}

int extrai_elemento(t_pilha *p) {
    if(p->topo < 2) return FRACASSO;
    p->dados[p->topo-2] = p->dados[p->topo-1];
    p->topo--;
    return SUCESSO;
}

int amassa_topo (t_pilha *p, int i) {
    if(esta_vazia(p)) {
        return empilha(p, i);
    }
    if(i > p->dados[p->topo-1]) {
        p->dados[p->topo-1] = i;
    } else {
        return empilha(p, i);
    }
    return SUCESSO;
}

int amassa_pilha(t_pilha *p, int i) {
    int j = p->topo - 1;
    if(esta_vazia(p)) {
        return empilha(p, i);
    }
    if(i > p->dados[j]) {
        while (j >= 0 && i > p->dados[j]) {
            p->dados[j] = i;
            j--;
        } 
    } else {
        return empilha(p, i);
    }
    return SUCESSO;
}

int sobrecarrega_pilha(t_pilha *p, int i) {
    if(!empilha(p, i)) return FRACASSO;
    empilha(p, i);
    return SUCESSO;
}

int esta_cheia2 (t_pilha *p) {
    return p->topo == p->capacidade - 1;
};
int empilha2 (t_pilha *p, int i) {
    if(esta_cheia2(p)) return FRACASSO;
    p->dados[p->topo] = i;
    p->topo++;
    return SUCESSO;
}
