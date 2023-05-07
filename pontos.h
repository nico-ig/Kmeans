#ifndef _PONTOS_
#define _PONTOS_

#include <bits/stdc++.h>

using namespace std;

// Define um unico ponto
template<typename type>
class ponto
{
  private:
    int dim;

  public:
    vector<type> coordenadas;   // Vetor de coordenadas do ponto

    void imprimePonto();
    int dimensao() { return dim; }
    void push_back(type coord) { coordenadas.push_back(coord); }

    // Construtor
    ponto() {}
    ponto(initializer_list<type> val) :coordenadas(val) { dim = val.size(); }
    
    // Operadores
    type &operator[](int i) { return coordenadas[i]; }
    
    // Iteradores de begin/end
    type *begin() { return &coordenadas[0]; }
    type *end() { return begin() + dim; }
};

template<>
void ponto<double>::imprimePonto()
{
  bool first = true;
  cout << " (";
  cout << fixed << setprecision(2);

  for ( auto coord : coordenadas )
  {
    if ( !first ) { cout << ", "; }
    cout << coord;
    first = false;
  }
    cout << ")";
}

template<typename type>
void ponto<type>::imprimePonto()
{
  bool first = true;
  cout << " (";
    
  for ( auto coord : coordenadas )
  {
    if ( !first ) { cout << ","; }
    cout << coord;
    first = false;
  }
    cout << ")";
}

#endif
