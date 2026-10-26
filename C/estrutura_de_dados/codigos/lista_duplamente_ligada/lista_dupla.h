#include "no_duplo.h"

#define SUCESSO 1
#define FRACASSO 0

typedef struct {
    t_no_duplo *primeiro;
    t_no_duplo *ultimo;
} t_lista_dupla;

void inicia_lista (t_lista_dupla *);

void insere_inicio (int, t_lista_dupla *);
void insere_fim (int, t_lista_dupla *);

// a remoção checa lista vazia e retorna sucesso ou fracasso
// o elemento que sai volta por parametro - referencia 
int remove_inicio (t_lista_dupla *, int *);
int remove_fim (t_lista_dupla *, int *);

int lista_vazia (t_lista_dupla *);

void exibe_lista (t_lista_dupla *);

