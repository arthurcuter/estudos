#include "lista_dupla.h"

int main () {
    t_lista_dupla lista;
    inicia_lista(&lista);
    printf("lista foi inicializada\n");
    exibe_lista(&lista);
    insere_inicio(1, &lista);
    insere_inicio(2, &lista);
    insere_inicio(3, &lista);
    printf("\nlista depois das insercoes de inicio:\n");
    exibe_lista(&lista);
    insere_fim(10, &lista);
    insere_fim(20, &lista);
    insere_fim(30, &lista);
    printf("\nlista depois das insercoes de fim:\n");
    exibe_lista(&lista);
    int que_saiu;
    if (remove_inicio(&lista, &que_saiu)) {
        printf("\n%d foi removido do inicio\n", que_saiu);
        printf("lista depois da remocao de inicio:\n");
        exibe_lista(&lista);
    } else {
        printf("problemas tecnicos, tente mais tarde\n");
    }

    if (remove_fim(&lista, &que_saiu)) {
        printf("\n%d foi removido do final\n", que_saiu);
        printf("lista depois da remocao de fim:\n");
        exibe_lista(&lista);
    } else {
        printf("problemas tecnicos, tente mais tarde\n");
    }
    return 0;
}