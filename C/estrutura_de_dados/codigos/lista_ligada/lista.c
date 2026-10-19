#include "lista.h"

void inicia_lista (t_lista *lista) {
    lista->primeiro = NULL;
    lista->tamanho = 0;
}
int lista_vazia (t_lista *lista) {
    return lista->tamanho == 0;
}
void insere_inicio (int elemento, t_lista *lista) {

}