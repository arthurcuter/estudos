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

    // para o lar: desenvolver uma funcao para cada uma das tarefas: 
    // 1. inserir um elemento numa posicao especifica. considere o primeiro como posicao 1
    // 2. remover um elemento de uma posicao especifica. se posicao for maior que tamanho, retornar fracasso
    // 3. remover a primeira ocorrencia de um elemento
    // 4. calcular o tamanho da lista
    // 5. verificar se um elemento esta na lista
    // 6. contar o numero de ocorrencias de um elemento

    return 0;
}