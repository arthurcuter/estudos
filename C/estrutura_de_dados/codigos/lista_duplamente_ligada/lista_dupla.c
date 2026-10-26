#include "lista_dupla.h"

void inicia_lista (t_lista_dupla *p_lista) {
    p_lista->primeiro = NULL;
    p_lista->ultimo = NULL;
}

int lista_vazia (t_lista_dupla *p_lista_dupla) {
    return p_lista_dupla->primeiro == NULL;
}

void insere_inicio (int info, t_lista_dupla *p_lista) {
    t_no_duplo * novo = constroi_no(info);
    if(lista_vazia(p_lista)) {
        p_lista->ultimo = novo;
    } else {
        novo->prox = p_lista->primeiro;
        p_lista->primeiro->ant = novo;
    }
    p_lista->primeiro = novo;
}

void insere_fim (int info, t_lista_dupla *p_lista) {
    t_no_duplo * novo = constroi_no(info);
    if(lista_vazia(p_lista)) {
        p_lista->primeiro = novo;
    } else {
        novo->ant = p_lista->ultimo;
        p_lista->ultimo->prox = novo;
    }
    p_lista->ultimo = novo;
}

int remove_inicio (t_lista_dupla *p_lista, int *p_int) {
    if(lista_vazia(p_lista)) return FRACASSO;
    *p_int = p_lista->primeiro->info;
    t_no_duplo *temp = p_lista->primeiro;
    if(p_lista->primeiro == p_lista->ultimo) { // tinha um unico nó
        p_lista->primeiro = NULL;
        p_lista->ultimo = NULL;
        // zerou a lista
    } else {
        p_lista->primeiro = p_lista->primeiro->prox;
        p_lista->primeiro->ant = NULL;
    }
    free(temp);
    return SUCESSO;

}
int remove_fim (t_lista_dupla *p_lista, int *p_int) {
    if(lista_vazia(p_lista)) return FRACASSO;
    *p_int = p_lista->ultimo->info;
    t_no_duplo * temp = p_lista->ultimo;
    if(p_lista->primeiro == p_lista->ultimo) {
        p_lista->primeiro = NULL;
        p_lista->ultimo = NULL;
    } else {
        p_lista->ultimo = p_lista->ultimo->ant;
        p_lista->ultimo->prox = NULL; 
    }
    free(temp);
    return SUCESSO;
}

void exibe_lista (t_lista_dupla *p_lista) {
    if(lista_vazia(p_lista)) {
        printf("lista vazia\n");
    } else {
        t_no_duplo * temp = p_lista->primeiro;
        printf("// = ");
        while(temp != NULL) {
            printf("%d = ", temp->info);
            temp = temp->prox;
        }
        printf("//\n");
    }
}

