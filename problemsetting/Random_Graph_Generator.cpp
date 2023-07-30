#include <bits/stdc++.h>
using namespace std;

// Random Number Generator.
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

auto GenerateRandomGraph(int N, int M) -> vector<array<int, 2>> { 
  /*
   * Genera un grafo no dirigido con N nodos y M aristas en esperanza, en O(N + M) tiempo en esperanza. 
   * Es la implementación del algoritmo 1 expuesto en el siguiente artículo:
   * Batagelj, Vladimir; Brandes, Ulrik (2005). Efficient generation of large random networks.
   * doi:10.1103/PhysRevE.71.036113
  */

  vector<array<int, 2>> Edges;

  // La probabilidad adecuada para que el valor esperado sea M.
  assert(2LL*M < N*1LL*(N - 1) && N > 0);
  long double p = ((long double) M*1LL*2 / (N*1LL*(N - 1)));
  int v = 1; long long int w = -1; 
  while (v < N) {
    long double r = ((long double) (rng() % (~0ULL) / (~0ULL)));
    w += 1 + (long long int)(log(1 - r)/log(1 - p));
    while (w >= v && v < N) {
      w -= v; v++;
    }
    if (v < N) Edges.push_back({v, w});
  }
  return Edges;
}
