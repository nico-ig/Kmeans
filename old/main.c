#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "utils.h"
#include "pontos.h"

int main()
{
  int **v_comb;
  double **v_pontos;

  srand(time(0));
 
  /* Gera os pontos */
  v_pontos = geraPontos(QTD_P, DIM_P, P_MIN, P_MAX);

  /* Gera todas as combinações de divisao dos pontos nos clusters */
  v_comb = geraVetorComb(K, QTD_P);

  imprime(v_comb, v_pontos);
   
  encerra(v_pontos, v_comb, QTD_P, QTD_P);
  return 0;
}
