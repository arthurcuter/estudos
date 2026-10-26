#include "lista_dupla.h"

void inicia_lista (t_lista_dupla *p_lista) {
    p_lista->primeiro = NULL;
    p_lista->ultimo = NULL;
}

int lista_vazia (t_lista_dupla *p_lista_dupla) {
    return p_lista_dupla->primeiro == NULL;
}