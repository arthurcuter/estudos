#include "fila.h"

void inicia_fila (t_fila *f) {
    f->primeiro = f->ultimo = NULL; // ambos recebem NULL
}
int fila_vazia (t_fila *f) {
    return f->primeiro == NULL;
}

struct no * enfileira (int i, t_fila *f) {
    struct no * novo = constroi_no(i);
    if(novo) {
        if(fila_vazia(f)) {
            f->primeiro = novo;
        } else {
            f->ultimo->prox = novo;
        }
        f->ultimo = novo;
    }
    return novo;
}

int desenfileira (int *i, t_fila *f) {
    if(fila_vazia(f)) return FRACASSO;
    *i = f->primeiro->info;
    struct no * endereco_temp = f->primeiro;
    f->primeiro = f->primeiro->prox;
    if(f->primeiro == NULL) { // se esvaziou a fila
        f->ultimo == NULL;
    }
    free(endereco_temp);
    return SUCESSO;
}

void exibe_fila (t_fila *f) {
    if(fila_vazia(f)) {
        printf("fila vazia");
    } else {
        struct no * temp = f->primeiro;
        while (temp != NULL) {
            printf("%d ", temp->info);
            temp = temp->prox;
        }
        printf("\n");
    }
}