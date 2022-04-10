#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
 
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
*
*/
/* Analisis
* ==========
*
* mobious function: f(x) 
* f(pq) = f(q)f(p)
*
*
*/
 
const int Mx = 1e6 + 5;
int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  ll n; cin >> n; vector<ll> f(Mx), primos, bucket(Mx, 0);
  for (int i = 0; i < n; i++) {
    int x; cin >> x; bucket[x]++;
  }
 
  vector<bool> esprimo(Mx, true); 
  for (int i = 2; i < Mx; i++) {
    if (esprimo[i]) {
      primos.push_back(i); f[i] = -1;
    }
    for (int j = 0; j < (int)primos.size() && i*primos[j] < Mx; j++) {
      esprimo[i*primos[j]] = false;
      if (i%primos[j]) {
        f[i*primos[j]] = f[i]*f[primos[j]];
      } else {
        f[i*primos[j]] = 0; break;
      }
    }
  }
 
  ll ans = n*(n - 1)/2;
  for (int i = 2; i < Mx; i++) {
    if (f[i] == 0) continue;
    ll val = 0;
    for (int j = 1; j*i < Mx; j++) val += bucket[j*i];
    ans += f[i]*val*(val - 1)/2;
  }
  cout << ans;
}
