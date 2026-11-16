#include "lista.h"

int main () {
    t_lista lista;
    inicia_lista(&lista);
    insere_inicio (7, &lista);
    exibe_lista(&lista);
    insere_fim (4, &lista);
    exibe_lista(&lista); 
    insere_inicio (9, &lista);
    exibe_lista(&lista);
    remove_fim (&lista);
    exibe_lista(&lista);
    insere_fim (2, &lista);
    exibe_lista(&lista);
    remove_inicio (&lista);
    exibe_lista(&lista);
    insere_inicio (5, &lista);
    exibe_lista(&lista);
    remove_fim (&lista);
    exibe_lista(&lista);
    remove_fim (&lista);
    exibe_lista(&lista);

    return 0;

}