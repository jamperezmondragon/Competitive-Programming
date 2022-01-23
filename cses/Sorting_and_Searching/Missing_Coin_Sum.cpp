#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//debuging 
const bool DEB = false;
#define DEBUG if (DEB) 
/* Informative
* ==============
* Status: 
* link del problema: 
* submission:
*/
/*
* Comments
* =========
*
*/
/* Analisis
* ==========
* este problema está bien chido, o sea si asumes que el arreglo a[i] está
* ordenado, y que 
*
* \sum_{0 <= i < k} a[i] >= a[k + 1] - 1 para todo k menor que n, 
*
* entonces podemos mostrar inductivamente que todos los valores menores
* o iguales a \sum_{i < n} a[i] se pueden hacer.
* Entonces solo tenemos que encontrar el valor k para el que
* esto se rompe y ya.
*
*/
//int const M = 1000000007;
 
int main() {
  int n; cin >> n; vector<int> vec(n);
  for (auto &e : vec) cin >> e;
  sort(vec.begin(), vec.end());
  ll s = 0; 
  for (int i = 0; i < n; i++) {
    if (s < vec[i] - 1) break;
    s += vec[i];
  }
  cout << s + 1;
}
