#include "fila.h"

int main () {
    t_fila fila;
    inicia_fila(&fila);
    if(fila_vazia(&fila)) {
        printf("fila inicializada, esta vazia\n");
    } else {
        printf("problemas tecnicos\n");
    }
    if(enfileira(10, &fila)) {
        printf("10 enfileirado com sucesso\n");
        exibe_fila(&fila);
    } else {
        printf("falha na alocacao de memoria\n");
    }
    // int i = 1;
    // while(enfileira (i, &fila)) {
    //     printf("%d ", i++);
    // }
    enfileira(20, &fila);
    enfileira(30, &fila);
    enfileira(40, &fila);
    exibe_fila(&fila);
    int que_sai;
    if(desenfileira(&que_sai, &fila)) {
        printf("%d foi atendido\n", que_sai);
        exibe_fila(&fila);
    } else {
        printf("fila vazia, nao ha o que remover\n");
    }
    
    return 0;
}