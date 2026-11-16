#include "lista.h"

int main () {

    t_lista lista;
    inicia_lista(&lista);
    insere_fim(1, &lista);
    insere_fim(2, &lista);
    insere_fim(3, &lista);
    insere_fim(4, &lista);
    insere_fim(6, &lista);
    exibe_lista(&lista);
    insere_ordenado(10, &lista);
    exibe_lista(&lista);

    return 0;
}