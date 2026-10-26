#include <stdio.h>
#include <stdlib.h>

typedef struct no_duplo {
    int info;
    struct no_duplo *prox;
    struct no_duplo *ant;
} t_no_duplo;

t_no_duplo * constroi_no (int);