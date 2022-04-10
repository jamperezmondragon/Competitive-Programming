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
 
int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int tt; cin >> tt;
  while (tt--) {
    ll a, b, c, exp = 1, ans = 1; cin >> a >> b >> c;

    for (ll i = 0, j = b; i < 32; i++, (j *= j) %= (M - 1)) {
      if (c&(1<<i))  exp = (j*exp)%(M - 1);
    }

    for (ll i = 0, j = a; i < 32; i++, (j *= j) %= M) {
      if (exp&(1<<i))  ans = (j*ans)%M;
    }
    cout << ans << "\n";
  }
}
