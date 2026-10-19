#include "no.h"

typedef struct lista {
    struct no *primeiro;
    int tamanho;
} t_lista;

void inicia_lista (t_lista *);
int lista_vazia (t_lista *);
void insere_inicio (int, t_lista *);
void exibe_lista (t_lista *);
int remove_inicio (t_lista *);
void insere_fim (int, t_lista *);
int remove_fim (t_lista *);