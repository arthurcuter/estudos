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

int valor_topo(t_pilha *p) {
    // considerando que quem chamou a funcao testou pilha vazia
    return p->dados[p->topo-1];
}

void exibe_pilha(t_pilha *p) {
    if(esta_vazia(p)) {
        printf("Pilha vazia\n");
    } else {
        int i = p->topo - 1;
        while(i >= 0) {
            printf("Elemento %d da pilha: %d\n", i, p->dados[i]);
            i--;
        }
    }
}

int extrai_elemento(t_pilha *p) {
    if(tamanho(p) < 2) return -1;
    int aux, o_que_sai;
    desempilha(p, &aux);
    desempilha(p, &o_que_sai);
    empilha(p, aux);
    return o_que_sai;

}

void amassa_topo (t_pilha *p, int i) {
    if(!esta_vazia(p) && valor_topo(p) < i) {
        int aux;
        desempilha(p, &aux);
    }
    empilha(p, i);
}

void amassa_pilha(t_pilha *p, int i) {
    while(!esta_vazia(p) && valor_topo(p) < i) {
        int aux;
        desempilha(p, &aux);
    }
    empilha(p, i);
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
