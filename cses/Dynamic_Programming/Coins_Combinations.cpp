#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//debuging 
const bool DEB = false;
#define DEBUG if (DEB) 
/* Informative
* ==============
* Status: AC
* link: https://cses.fi/problemset/result/3382434/
*/
/*
* Comments
* =========
*/
/* Analisis
* =========================
*
*/
ll const M = 1000000007;
int main() {
  int n, x; cin >> n >> x;
  vector<ll> dp(x + 1, 0), coins(n); dp[0] = 1;
  for (int i = 0; i < n; i++) {
    cin >> coins[i];
  }
  for (int i = 0; i <= x; i++) {
    for (ll e : coins) {
      if (e > i) continue;
      dp[i] += dp[i - e]; dp[i] %= M;
    }
  }
  cout << dp[x];
}

