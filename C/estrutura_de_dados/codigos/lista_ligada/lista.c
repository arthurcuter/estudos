#include "lista.h"

void inicia_lista (t_lista *lista) {
    lista->primeiro = NULL;
    lista->tamanho = 0;
}
int lista_vazia (t_lista *lista) {
    return lista->tamanho == 0;
}
void insere_inicio (int i, t_lista *lista) {
    struct no * novo = constroi_no(i);
    if(!lista_vazia(lista)) {
        novo->prox = lista->primeiro;
    }
    lista->primeiro = novo;
    lista->tamanho++;
}