#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "utils.h"
#include "kmeans.h"

double alet(double min, double max)
{
  double n, diff;

  /* Gera um numero aleatorio entre 0 e 1 */
  n = (double)rand() / RAND_MAX;
  
  diff = max - min;
  
  return min + n * diff;
}

void imprimeVetorDouble(double *v, int tam)
{

  for ( int i = 0; i < tam; i++ )
    printf(" %f |", v[i]);
  printf("\n");
}

void imprimeVetorInt(int *v, int tam)
{
  for ( int i = 0; i < tam; i++ )
    printf(" %d |", v[i]);
}

void copiaVetor(int *a, int *b, int tam)
{
  for ( int i = 0; i < tam; i++ )
    a[i] = b[i];
}

void encerra(double **v_pontos, int **v_bin, int qtd, int dim)
{
  /* Libera a memoria do vetor de pontos */
  for ( int i = 0; i < qtd; i++ )
    free(v_pontos[i]);
  free(v_pontos);

  /* Libera a memoria do vetor de binarios */
  for ( int i = 0; i < pow(2, dim); i++ )
    free(v_bin[i]);
  free(v_bin);
}

// Imprime todas as combinações e o valor da funcao
void imprime(int **v_comb, double **v_pontos)
{
  /* Imprime todos os pontos */
  printf("\n---------------------Pontos--------------------\n\n");

  /* Imprime cabecalho */
  printf("                   Coordenadas\n");
  printf(" Ponto |");
  for ( int i = 0; i < DIM_P; i++ )
    printf("     %d    |", i);
  printf("\n");

  /* Imprime as coordenadas de cada ponto */
  for ( int i = 0; i < QTD_P; i++ )
  {
    printf("   %d   |", i);
    imprimeVetorDouble(v_pontos[i], DIM_P);
  }
  
  printf("\n---------------------Kmeans--------------------\n\n");
  
  /* Imprime o cabecalho */
  printf(" Comb |   Pontos  |     F     |\n");

  /* Calcula e imprime a funcao f para todas as combinacoes */
  for ( int i = 0; i < pow(K, QTD_P); i++ )
  {
    printf("%4d  |", i);
    imprimeVetorInt(v_comb[i], QTD_P);
    double f = kmeans(v_pontos, v_comb[i], K, QTD_P, DIM_P);
    printf(" %9f |\n", f);
  }
  printf("\n");
}
