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

int busca (int x, t_lista *lista) {
    struct no * percorre = lista->primeiro;
    int posicao = 0;
    while (percorre != NULL) {
        if(percorre->info == x) {
            return posicao;
        }
        percorre = percorre->prox;
        posicao++;
    }
    return -1;
} 

int conta_ocorrencias (int x, t_lista *lista) {
    if(lista_vazia(lista)) return 0;
    struct no * percorre = lista->primeiro;
    int ocorrencias = 0;
    while (percorre != NULL) {
        if(percorre->info == x) {
            ocorrencias++;
        }
        percorre = percorre->prox;
    }
    return ocorrencias;
}

int maior_elemento (t_lista *lista, int *maior) {
    if(lista_vazia(lista)) return FRACASSO;
    struct no * percorre = lista->primeiro->prox;
    *maior = lista->primeiro->info;
    while (percorre != NULL) {
        if(percorre->info > *maior) {
            *maior = percorre->info;
        }
        percorre = percorre->prox;
    }
    return SUCESSO;
}

void insere_ordenado (int i, t_lista *lista) {
    if(lista_vazia(lista) || i <= lista->primeiro-> info) {
        insere_inicio(i, lista);
    } else {
        struct no * percorre = lista->primeiro;
        while(percorre->prox != NULL && percorre->prox->info < i) { 
            percorre = percorre->prox;
        }
        struct no * novo = constroi_no(i);
        novo->prox = percorre->prox;
        percorre->prox = novo;
        lista->tamanho++;   
    }
}

void ordena_lista (t_lista *origem, t_lista *destino) {
    struct no * percorre = origem->primeiro;
    while (percorre != NULL) {
        insere_ordenado(percorre->info, destino);
        struct no * aux_no = percorre;
        percorre = percorre->prox;
        free(aux_no);
    }
    origem->primeiro = NULL;
    origem->tamanho = 0;
}