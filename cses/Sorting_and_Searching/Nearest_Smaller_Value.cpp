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
*
*/
//int const M = 1000000007;
 
int main() {
  int n, ans; cin >> n; vector<int> vec(n + 1); stack<int> pila;
  for (int i = 1; i <= n && cin >> vec[i]; i++) {
    while (!pila.empty() && vec[i] <= vec[pila.top()]) {
      pila.pop();
    }
    if (pila.empty()) ans = 0; 
    else ans = pila.top();
    pila.push(i); cout << ans << " ";
  }
}
