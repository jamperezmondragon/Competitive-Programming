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
const int M = 1e9+7;
ll expon(ll x, ll exp, ll ans = 1) {
  for (ll i = 0, j = x; i < 33; i++, j = (j*j)%M) {
    if (exp&(1<<i)) (ans *= j) %= M;
  }
  return ans;
}
 
int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n; cin >> n;

  ll sum = 0, numdiv1 = 1, numdiv2 = 1, val = 1;
  for (int i = 0; i < n; i++) {
    ll p, e; cin >> p >> e;
    (sum *= (expon(p, e + 1) - 1)*expon(p - 1, M - 2)) %= M;
    (numdiv1 *= e + 1) %= M;
    (numdiv2 *= e + 1) %= (M - 1);
    (val *=  expon(p, e)) %= M;
  }
  val = expon(val, numdiv2/2);
  cout << numdiv1 << " " << sum << " " << val;
}
