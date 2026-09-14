#include "pilha.h"

int main () {

    t_pilha pilha;
    constroi_pilha(5, &pilha);
    exibe_pilha(&pilha);
    empilha(&pilha, 10);
    empilha(&pilha, 20);
    empilha(&pilha, 30);
    exibe_pilha(&pilha);
    int desempilhado;
    desempilha(&pilha, &desempilhado);
    exibe_pilha(&pilha);
    desempilhado = extrai_elemento(&pilha);
    printf("%d estava abaixo do topo\n", desempilhado);
    exibe_pilha(&pilha);
    empilha(&pilha, 15);
    empilha(&pilha, 5);
    exibe_pilha(&pilha);
    amassa_topo(&pilha, 10);
    exibe_pilha(&pilha);
    amassa_pilha(&pilha, 18);
    exibe_pilha(&pilha);

    return 0;
}