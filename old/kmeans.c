#include <math.h>
#include <stdlib.h>

#include "kmeans.h"

/* Calcula a norma elevada ao quadrado */
double norma(double *ponto, double *mi, int dim_p)
{
  double norma = 0;

  for ( int i = 0; i < dim_p; i++ )
    norma += pow(ponto[i]-mi[i], 2);
  
  return norma;
}

/* Calcula a media dos pontos para cada cluster */
double **calc_mi(double **pontos, int *comb, int k, int tam, int dim_p)
{
  int *qtd;
  double **mi;

  /* Aloca o vetor para as medias */
  if ( ! (mi = malloc(sizeof(double *) * k)) ) { return NULL; }

  /* Aloca os vetores com o valor para cada coordenada */
  for ( int i = 0; i < k; i++ )
    if ( ! (mi[i] = calloc(dim_p, sizeof(double))) ) { return NULL; }

  /* Aloca o vetor com a quantidade de pontos em cada cluster */
  if ( ! (qtd = calloc(k, sizeof(int))) ) { return NULL; }

  /* Calcula a soma das coordenadas para cada cluster */
  for ( int i = 0; i < tam; i++ )
  {
    /* Soma as coordenadas */
    for ( int j = 0; j < dim_p; j++ )
      mi[comb[i]][j] += pontos[i][j];
    qtd[comb[i]]++;
  }

  /* Divide a soma das coordenadas de cada cluster pela quantidade de pontos */
  for ( int i = 0; i < k; i++ )
  {
    /* Divide cada coordenada pela quantidade de pontos */
    for ( int j = 0; j < dim_p; j++ )
      mi[i][j] /= qtd[i];
  }

  return mi;
}

double kmeans(double **pontos, int *comb, int tam, int k, int dim_p)
{
  double **mi; /* Vetor com as medias de cada cluster */
  double f = 0;

  /* Mi eh um vetor com as medias dos pontos de cada cluster */
  mi = calc_mi(pontos, comb, k, tam, dim_p);

  /* Calcula a soma das normas de cada cluster */
  for ( int i = 0; i < k; i++ )
  {
    /* Calcula a norma se o ponto pertence ao cluster i */
    for ( int j = 0; j < tam; j++ )
      if ( comb[j] == i )
        f +=norma(pontos[j], mi[i], dim_p);
  }

  for ( int i = 0; i < dim_p; i++ )
    free(mi[i]);
  free(mi);

  return f;
}
