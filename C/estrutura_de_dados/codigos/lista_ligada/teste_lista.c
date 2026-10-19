#include "lista.h"

int main () {
    t_lista lista;
    inicia_lista(&lista);
    printf("lista depois que foi inicializada: \n");
    exibe_lista(&lista);
    insere_inicio(2, &lista);
    insere_inicio(1, &lista);
    insere_inicio(3, &lista);
    printf("\nlista depois das insercoes de inicio:\n");
    exibe_lista(&lista);
    if(!lista_vazia(&lista)) {
        printf("%d foi removido do inicio\n", remove_inicio(&lista));
        printf("\nlista depois da remocao de inicio:\n");
        exibe_lista(&lista);
    }
    insere_fim(10, &lista);
    insere_fim(20, &lista);
    insere_fim(30, &lista);
    printf("\nlista depois das insercoes de fim:\n");
    exibe_lista(&lista);
    if(!lista_vazia(&lista)) {
        printf("%d foi removido do final\n", remove_fim(&lista));
        printf("\nlista depois da remocao de fim:\n");
        exibe_lista(&lista);
    }
    return 0;
}