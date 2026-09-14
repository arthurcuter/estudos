#include "pilha.h"

int main () {

    t_pilha pilha;

    constroi_pilha(10, &pilha);
    for(int i = 0; i < 10; i++) {
        empilha(&pilha, i);
    }
    exibe_pilha(&pilha);
    extrai_elemento(&pilha);
    printf("===============\n");
    exibe_pilha(&pilha);
    printf("===============\n");
    amassa_pilha(&pilha, 10);
    exibe_pilha(&pilha);
    printf("===============\n");
    extrai_elemento(&pilha);
    sobrecarrega_pilha(&pilha, 7);
    exibe_pilha(&pilha);

    return 0;
}