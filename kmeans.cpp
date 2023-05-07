#include <bits/stdc++.h>

#include "conjuntos.h"
#include "pontos.h"

using namespace std;

int main()
{
  conjunto<int> S {{1, 3}, {4, 5}, {8, 0}};
 
  // Cria dois clusters e adiciona os pontos nele
  vector<conjunto<int>> clusters (2);
  clusters[0].push_back(S[0]);
  clusters[0].push_back(S[1]);
  clusters[0].push_back(S[2]);

  // Calcula o valor da funcao
  double f = 0;
  for ( auto k : clusters )
    f += k.size()*k.var(); 

  cout << fixed << setprecision(2);
  cout << "CLUSTER 0\n";
  cout << "Variancia: " << clusters[0].var() << " Tamanho: " << clusters[0].size() << "\n\n";

  cout << "CLUSTER 1\n";
  cout << "Variancia: " << clusters[1].var() << " Tamanho: " << clusters[1].size() << "\n\n";
  
  cout << "Funcao: " << f << "\n";
}

