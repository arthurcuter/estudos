#include "no_duplo.h"

t_no_duplo * constroi_no (int info) {
    t_no_duplo *novo = (t_no_duplo *) malloc(sizeof(t_no_duplo));
    if(novo != NULL) {
        novo->info = info;
        novo->ant = NULL;
        novo->prox = NULL;
    }
    return novo;
}