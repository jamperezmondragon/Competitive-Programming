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
*
*
*/
 

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);

  ll k, n, ans = 0; cin >> n >> k; vector<ll> a(k);
  for (auto &e : a) cin >> e;
  for (ll bitmask = 1; bitmask < 1<<k; bitmask++) {
    ll sz = 0, prod = 1;
    for (int i = 0; i < k; i++) {
      if (bitmask&(1<<i)) {
        sz++; prod = (a[i] > n/prod) ? n + 1 : prod*a[i];
      }
    }
    if (sz&1) ans +=  n/prod;
    else ans -=  n/prod;
  }
  cout << ans;
}
