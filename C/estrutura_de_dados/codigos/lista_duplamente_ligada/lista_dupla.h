#include "no_duplo.h"

typedef struct {
    t_no_duplo *primeiro;
    t_no_duplo *ultimo;
} t_lista_dupla;

void inicia_lista (t_lista_dupla *);

void insere_inicio (int, t_lista_dupla *);
void insere_fim (int, t_lista_dupla *);

int remove_inicio (t_lista_dupla *);
int remove_fim (t_lista_dupla *);

int lista_vazia (t_lista_dupla *);

