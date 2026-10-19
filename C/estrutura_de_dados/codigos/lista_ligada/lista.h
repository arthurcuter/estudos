#include "no.h"

typedef struct lista {
    struct no *primeiro;
    int tamanho;
} t_lista;

void inicia_lista (t_lista *);
int lista_vazia (t_lista *);
void insere_inicio (int, t_lista *);
