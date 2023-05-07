#ifndef _CONJUNTOS_
#define _CONJUNTOS_

#include <bits/stdc++.h>

#include "pontos.h"

using namespace std;

// Define um conjunto de pontos
template<typename type>
class conjunto
{
  private:
    vector<ponto<type>> pontos; // Vetor de pontos
    
  public:
    // Funcoes
    double var();
    ponto<double> mi();
    void imprimeConjunto();
    int size() { return pontos.size(); }
    void push_back(ponto<type> p) { pontos.push_back(p); }

    // Construtor
    conjunto() {} 
    conjunto(initializer_list<ponto<type>> lp) :pontos(lp) {}
    
    // Operadores
    ponto<type> &operator[](int i) { return pontos[i]; }
  
    // Iteradores de begin/end
    ponto<type> *begin() { return &pontos[0]; }
    ponto<type> *end() { return begin() + size(); }
};

template<typename type>
void conjunto<type>::imprimeConjunto()
{
  cout << "Pontos:"; 
  
  for ( auto p : pontos )
    p.imprimePonto();
  
  cout << "\n";
}

template<typename type>
ponto<double> conjunto<type>::mi()
{
  ponto<double> mi;
  
  int dim = pontos[0].dimensao();
  
  // Inicizaliza as coordenadas da media em 0
  for ( int i = 0; i < dim; i++ )
    mi.push_back(0);

  // Para cada ponto, acumula a soma em cada coordenada
  for ( auto p : pontos )
    for ( int i = 0; i < dim; i++ )
      mi[i] += p[i];

  // Divide o valor acumulado de cada coordenada pela qtd de pontos no conjunto
  for ( int i = 0; i < dim; i++ )
    mi[i] /= pontos.size();

  return mi;
}

template<typename type>
double conjunto<type>::var()
{ 
  if ( !pontos.size() ) { return 0; }

  double var = 0;
  int dim = pontos[0].dimensao();
  ponto<double> mi = this->mi();
  double p = 10.89;

  // Para cada ponto do conjunto, calcula a distancia do ponto medio
  for ( auto p : pontos )
    for ( int i = 0; i < dim; i++ )
      var += pow(p[i]-mi[i], 2);
  
  return var/(double)pontos.size(); 
}

#endif
