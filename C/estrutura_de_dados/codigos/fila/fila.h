#include "/workspaces/estudos/C/estrutura_de_dados/codigos/lista_ligada/no.h"

#define SUCESSO 1
#define FRACASSO 0

typedef struct {
    struct no * primeiro;
    struct no * ultimo;
} t_fila; 

void inicia_fila (t_fila *);
int fila_vazia (t_fila *);
struct no * enfileira (int, t_fila *);
// caso a alocação de memória tenha falhado, devolve NULL
int desenfileira (int *, t_fila *);
// a função retorna SUCESSO ou FRACASSO e o elemento volta por parâmetro referência

void exibe_fila (t_fila *);