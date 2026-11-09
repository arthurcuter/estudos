#include "fila.h"

void inicia_fila (t_fila *f) {
    f->primeiro = f->ultimo = NULL; // ambos recebem NULL
}
int fila_vazia (t_fila *f) {
    return f->primeiro == NULL;
}