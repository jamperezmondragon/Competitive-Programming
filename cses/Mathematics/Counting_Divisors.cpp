#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
*
*
*/
 
const int Mx = 1e6+102;

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  
  bool esprimo[Mx]; memset(esprimo, true, sizeof(esprimo));
  vector<ll> primos, d(Mx, 1), cnt(Mx, 1);

  for (ll i = 2; i < Mx; i++) {
    if (esprimo[i]) {
      primos.push_back(i); d[i] = 2; cnt[i] = 1;
    }
    for (int j = 0; j < (int)primos.size() && primos[j]*i < Mx; j++) {
      esprimo[i*primos[j]] = false;
      if (i%primos[j] == 0) {
        cnt[i*primos[j]] = cnt[i] + 1;
        d[i*primos[j]] = (d[i] - d[i/primos[j]])*(cnt[i*primos[j]] + 1);
      } else {
        cnt[i*primos[j]] = 1;
        d[i*primos[j]] = d[i]*2;
      }
    }
  }
  //for (auto e : primos) cout << e << " ";
  int tt; cin >> tt;
  while (tt--) {
    int n; cin >> n; cout << d[n] << "\n";
  }
}
