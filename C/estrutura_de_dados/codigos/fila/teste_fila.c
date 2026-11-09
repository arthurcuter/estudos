#include "fila.h"

int main () {
    t_fila fila;
    inicia_fila(&fila);
    if(fila_vazia(&fila)) {
        printf("fila inicializada, esta vazia");
    } else {
        printf("problemas tecnicos");
    }

    return 0;
}