#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "pontos.h"
#include "utils.h"

/* Wrapper da funcao geraVetorComb */
int geraVetorComb_(int **v_comb, int *comb, int tam, int n, int j, int i)
{
  if (i == tam)
  {
    copiaVetor(v_comb[j], comb, tam);
    return ++j;
  }

  /* Gera todas as combinacoes */
  for ( int set = 0; set < n; set++ )
  {
    comb[i] = set;
    j = geraVetorComb_(v_comb, comb, tam, n, j, i+1);
  }

  return j;
}

int **geraVetorComb(int n, int tam)
{
  int **v_comb, *comb, qtd;
  qtd = pow(n, tam);

  /* Aloca o vetor com todas as combinacoes */
  if ( ! (v_comb = malloc(sizeof(int*) * qtd)) )
  {
    fprintf(stderr, "Falha na alocacao do vetor de combinacoes\n");
    exit(1);
  }

  /* Aloca os vetores para cada combinacao */
  for ( int i = 0; i < qtd; i++ )
  {
    if ( ! (v_comb[i] = malloc(sizeof(int) * qtd)) )
    {
      fprintf(stderr, "Falha na alocacao dos vetores do vetor de combinacao");
      exit(1);
    }
  }

  if ( ! (comb = malloc(sizeof(int) * tam)) )
  {
    fprintf(stderr, "Falha na alocacao da combinacao\n");
    exit(1);
  }
  
  geraVetorComb_(v_comb, comb, tam, n, 0, 0);

  free(comb);
  return v_comb;
}

double **geraPontos(int qtd, int dim, int min, int max)
{
  double **v_pontos, *ponto;

  /* Aloca um espaco para qtd de pontos */
  if ( ! (v_pontos = malloc(sizeof(double*) * qtd)) )
  {
    fprintf(stderr, "Falha na alocacao do vetor de pontos\n");
    exit(1);
  }

  /* Gera qtd de pontos de dimensao dim */
  for ( int i = 0; i < qtd; i++ )
  {
    /* Aloca um espaco para o ponto de dimensao DIM_P */
    if ( ! (v_pontos[i] = malloc(sizeof(double) * dim)) )
    {
      fprintf(stderr, "Falha na alocacao do ponto aleatorio\n");
      exit(1);
    }

    ponto = v_pontos[i];
    
    /* Gera valores aleatorios para o ponto */
    for ( int j = 0; j < dim; j++ )
      ponto[j] = alet(min, max);
  }

  return v_pontos;
}
