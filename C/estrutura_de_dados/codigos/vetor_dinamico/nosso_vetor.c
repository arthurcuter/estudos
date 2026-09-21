#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FRACASSO 0
#define SUCESSO 1
#define CAPACIDADE_MINIMA 10

typedef struct {
    int *v;
    int ocupacao;
    int capacidade;
} t_vetor;

void inicia_vetor (t_vetor *, int);
int esta_cheio (t_vetor *);
int esta_vazio (t_vetor *);
void insere (int, t_vetor *);
void exibe_vetor (t_vetor *, char *);
int remove_elemento (t_vetor *, int *);
//o retorno é SUCESSO ou FRACASSO, o elemento que sai, vem por parâmetro referência
void limpa_vetor (t_vetor *);
int busca_elemento (t_vetor *, int);

void gera_vetor (t_vetor *);
void bubble (t_vetor *);
void quick (t_vetor *, int, int);
void exibe_so_valores (t_vetor *, char *);

// int main () {
//     t_vetor vetor;
//     printf ("digite a capacidade do vetor: ");
//     int capacidade;
//     scanf ("%d", &capacidade);
//     printf ("endereco da estrutura: %p\n", &vetor);
//     inicia_vetor (&vetor, capacidade);
//     // if (insere(10, &vetor)) {
//     //     printf ("10 inserido com sucesso!\n");
//     // }
//     // else {
//     //     printf ("Nao foi possivel realizar a insercao\n");
//     // }
//     // insere (20, &vetor);
//     // exibe_vetor (&vetor, "primeiro vetor");
//     // t_vetor outro;
//     // inicia_vetor (&outro, 5);
//     // exibe_vetor (&outro, "outro vetor");
//     for (int i=1; i<=100; i++) {
//         insere (i, &vetor);
//         exibe_vetor (&vetor, "");
//     }
//     int elemento_removido;
//     if (remove_elemento (&vetor, &elemento_removido)) {
//         printf ("%d foi removido\n", elemento_removido);
//         exibe_vetor (&vetor, "");
//     }
//     else {
//         printf ("vetor vazio, nao ha o que remover\n");
//     }
//     // while (!esta_vazio(&vetor)) {
//     //     remove_elemento (&vetor, &elemento_removido);
//     //     printf ("%d foi removido\n", elemento_removido);
//     //     exibe_vetor (&vetor, "");
//     // }
//     limpa_vetor(&vetor);
//     exibe_vetor (&vetor, "vetor depois do limpa_vetor");
//     return 0;
// }
// int main () {
//     t_vetor vetor;
//     int capacidade;
//     do {
//         printf ("\ndigite a capacidade do vetor, 0 encerra: ");
//         scanf ("%d", &capacidade);
//         if (capacidade > 0) {
//             inicia_vetor (&vetor, capacidade);
//             gera_vetor (&vetor);
//             printf ("ordenando...");
//             //exibe_so_valores (&vetor, "vetor original");
//             unsigned int inicio = time(0);
//             bubble (&vetor);
//             unsigned int fim = time(0);
//             printf ("tamanho: %d, tempo %u s\n", capacidade, fim - inicio);
//             //exibe_so_valores (&vetor, "vetor ordenado pelo bubble:");
//         }
//     } while (capacidade > 0);
//     return 0;
// }
int main () {
    t_vetor vetor;
    int capacidade;
    srand (time(0));
    printf ("digite a capacidade do vetor, 0 encerra: ");
    scanf("%d", &capacidade);
    while (capacidade > 0) {
        inicia_vetor (&vetor, capacidade);
        gera_vetor(&vetor);
        exibe_so_valores (&vetor, "primeiro vetor");
        bubble(&vetor);
        exibe_so_valores (&vetor, "primeiro vetor ordenado pelo bubble");
        gera_vetor(&vetor);
        exibe_so_valores(&vetor, "segundo vetor");
        quick(&vetor, 0, capacidade-1);
        exibe_so_valores(&vetor, "segundo vetor ordenado pelo quick");
        printf("\ndigite a nova capacidade , 0 encerra: ");
        scanf("%d", &capacidade);
        
    }
    return 0;
}
void inicia_vetor (t_vetor *p_vetor, int capacidade) {
    if (p_vetor->v != NULL)
        free(p_vetor->v); //liberando a memória
    p_vetor->v = (int *) malloc (capacidade * sizeof(int));
    //printf ("endereco do vetor dentro da estrutura: %p\n", p_vetor->v);
    p_vetor->ocupacao = 0;
    p_vetor->capacidade = capacidade;
}
int esta_cheio (t_vetor *p_vetor) {
    // if (p_vetor->capacidade == p_vetor->ocupacao)
    //     return 1;
    // return 0;
    return p_vetor->capacidade == p_vetor->ocupacao;
}
int esta_vazio (t_vetor *p_vetor) {
    // if (p_vetor->ocupacao == 0)
    //     return 1;
    // return 0;
    return p_vetor->ocupacao == 0;
}
// int insere (int i, t_vetor *p_vetor) {
//     if (esta_cheio(p_vetor)) {
//         return FRACASSO;
//     }
//     else {
//         p_vetor->v[p_vetor->ocupacao] = i;
//         p_vetor->ocupacao++;
//         return SUCESSO;
//     }
// }
// void dobra (t_vetor *p_vetor) {
//     int *temp = (int *) malloc (sizeof(int) * p_vetor->capacidade * 2);
//     for (int i=0; i < p_vetor->ocupacao; i++)
//         temp[i] = p_vetor->v[i];
//     free (p_vetor->v);
//     p_vetor->v = temp;
//     p_vetor->capacidade = p_vetor->capacidade * 2;
// }
// void reduz_a_metade (t_vetor *p_vetor) {
//     int *temp = (int *) malloc (sizeof(int) * p_vetor->capacidade / 2);
//     for (int i=0; i<p_vetor->ocupacao; i++)
//         temp[i] = p_vetor->v[i];
//     free (p_vetor->v);
//     p_vetor->v = temp;
//     p_vetor->capacidade = p_vetor->capacidade / 2;
// }
void redimensiona (t_vetor *p_vetor, int novaCapacidade) {
    int *temp = (int *) malloc (sizeof(int) * novaCapacidade);
    for (int i=0; i<p_vetor->ocupacao; i++) 
        temp[i] = p_vetor->v[i];
    free(p_vetor->v);
    p_vetor->v = temp;
    p_vetor->capacidade = novaCapacidade;
}
void insere (int i, t_vetor *p_vetor) {
    if (esta_cheio(p_vetor)) {
        redimensiona (p_vetor, p_vetor->capacidade * 2);
    }
    p_vetor->v[p_vetor->ocupacao] = i;
    p_vetor->ocupacao++;
}
void exibe_vetor (t_vetor *p_vetor, char * msg) {
    printf ("\n%s\n", msg);
    printf ("ocupacao = %d\n", p_vetor->ocupacao);
    printf ("capacidade = %d\n", p_vetor->capacidade);
    printf ("o vetor: ");
    for (int i=0; i < p_vetor->ocupacao; i++)
        printf ("%d ", p_vetor->v[i]);
    // for (int i= p_vetor->ocupacao; i < p_vetor->capacidade; i++)
    //     printf ("__ ");
    printf ("\n");
}
int remove_elemento (t_vetor *p_vetor, int * p_quem_sai) {
    if (esta_vazio(p_vetor)) return FRACASSO;
    p_vetor->ocupacao--;
    *p_quem_sai = p_vetor->v[p_vetor->ocupacao];
    if (p_vetor->capacidade >= CAPACIDADE_MINIMA * 2 &&
        p_vetor->ocupacao <= p_vetor->capacidade / 4)
        redimensiona (p_vetor, p_vetor->capacidade / 2);
    return SUCESSO;
}
void limpa_vetor (t_vetor *p_vetor) {
    p_vetor->ocupacao = 0;
}
int busca_elemento (t_vetor *p_vetor, int elemento) {
    for (int i=0; i<p_vetor->ocupacao; i++) {
        if (elemento == p_vetor->v[i])
            return 1;
    }
    return 0;
}
void gera_vetor (t_vetor *p_vetor) {
    for (int i=0; i < p_vetor->capacidade; i++) {
        p_vetor->v[i] = rand() % (p_vetor->capacidade * 10);
    }
    p_vetor->ocupacao = p_vetor->capacidade;
}
void bubble (t_vetor *p_vetor) {
    for (int i=1; i < p_vetor->capacidade; i++) {
        for (int j=0; j < p_vetor->capacidade - i; j++) {
            if (p_vetor->v[j] > p_vetor->v[j+1]) {
                int aux = p_vetor->v[j];
                p_vetor->v[j] = p_vetor->v[j+1];
                p_vetor->v[j+1] = aux;
            }
        }
    }
}

int partition (t_vetor *p_vetor, int p, int r) {
    int x = p_vetor->v[r];
    int i = p-1;
    int aux;
    for(int j = p; j < r; j++) {
        if(p_vetor->v[j] <= x) {
            i = i + 1;
            aux = p_vetor->v[i];
            p_vetor->v[i] = p_vetor->v[j];
            p_vetor->v[j] = aux;
        }
    }
    i = i + 1;
    aux = p_vetor -> v[r];
    p_vetor->v[r] = p_vetor->v[i];
    p_vetor->v[i] = aux;
    return i;
}

void quick (t_vetor *p_vetor, int p, int r) {
    if (p < r) {
        int q = partition(p_vetor, p, r);
        quick(p_vetor, p, q-1);
        quick(p_vetor, q+1, r);
    }
}

void exibe_so_valores (t_vetor *p_vetor, char *msg) {
    printf ("\n%s\n", msg);
    for (int i=0; i < p_vetor->ocupacao; i++) {
        printf ("%d ", p_vetor->v[i]);
    }
    printf("\n");
}

