#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//debuging 
const bool DEB = false;
#define DEBUG if (DEB) 
/* Informative
* ==============
* Status: AC
* link: https://cses.fi/problemset/result/3382408/
*/
/*
* Comments
* =========
* recuerda los errores de overflow duh
*/
/* Analisis
* =========================
*
*/
int main() {
  int n, x; cin >> n >> x;
  vector<ll> dp(x + 1, LLONG_MAX - 1), coins(n); dp[0] = 0;
  for (int i = 0; i < n; i++) {
    cin >> coins[i];
  }
  for (int i = 0; i <= x; i++) {
    for (ll e : coins) {
      if (i < e) continue;
      dp[i] = min(dp[i], dp[i - e] + 1);
    }
  }
  cout << ((dp[x] == LLONG_MAX - 1) ? -1 : dp[x]);
}
