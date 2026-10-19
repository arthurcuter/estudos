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
void exibe_lista(t_lista *lista) {
    if(lista_vazia(lista)) {
        printf("lista vazia\n");
    } else {
        struct no * percorre = lista->primeiro;
        while(percorre != NULL) { //vai ate o final
            printf("%d -> ", percorre->info);
            percorre = percorre->prox;
        }
        printf("//\n");
    }
}
int remove_inicio (t_lista *lista) {
    int aux_info = lista->primeiro->info;
    struct no * aux_primeiro = lista->primeiro;
    lista->primeiro = lista->primeiro->prox;
    free(aux_primeiro);
    lista->tamanho--;
    return aux_info;
}
void insere_fim (int i, t_lista *lista) {
    struct no * novo = constroi_no(i);
    if(lista_vazia(lista)) {
        lista->primeiro = novo;
    } else {
        struct no * percorre = lista->primeiro;
        while(percorre->prox != NULL) { // vai ate o ultimo elemento
            percorre = percorre->prox;
        }
        percorre->prox = novo;
    }
    lista->tamanho++;
}
int remove_fim (t_lista *lista) {
    int aux;
    if(lista->tamanho == 1) { // tem um elemento so
        aux = lista->primeiro->info;
        free(lista->primeiro);
        lista->primeiro = NULL;
    } else {
        struct no * percorre = lista->primeiro;
        while(percorre->prox->prox != NULL) {
            percorre = percorre->prox;
        }
        aux = percorre->prox->info;
        free(percorre->prox);
        percorre->prox = NULL;
    }
    lista->tamanho--;
    return aux;
}