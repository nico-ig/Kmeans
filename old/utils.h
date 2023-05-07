#ifndef _UTILS_
#define _UTILS_

#define P_MAX 100         /* Maior valor para as coordenadas */
#define P_MIN 1         /* Menor valor para as coordenadas */
#define QTD_P 8         /* Quantidade de pontos */
#define DIM_P 3         /* Dimensao dos pontos */
#define K 3             /* Quantidade de clusters */

/* Retorna um double entre min e max */
double alet(double min, double max);

void copiaVetor(int *a, int *b, int tam);

void encerra(double **v_pontos, int **v_bin, int qtd, int dim);

// Imprime todas as combinações e o valor da funcao
void imprime(int **v_comb, double **v_pontos);

#endif
