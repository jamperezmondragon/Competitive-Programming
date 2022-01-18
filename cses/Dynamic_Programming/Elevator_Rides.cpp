#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//debuging 
const bool DEB = false;
#define DEBUG if (DEB) 
/* Informative
* ==============
* Status: AC
* link del problema: https://cses.fi/problemset/task/1653
* submission: https://cses.fi/problemset/result/3397163/
*/
/*
* Comments
* =========
* keep it simple stupid duh
*/
/* Analisis
* ==========
*
*/
int const M = 1000000007;
int main() {
  int n, x; cin >> n >> x; vector<ll> w(n); 
  vector<pair<ll, ll>> dp(1<<n, {n + 1, 0}); dp[0] = {1, 0};
  for (auto &e : w) cin >> e;

  for (int i = 1; i < (1<<n); i++) {
    for (int k = 0; k < n; k++) {
      if (i&(1<<k)) {
        auto val = dp[i^(1<<k)];
        if (val.second + w[k] <= x) {
          val.second += w[k];
        } else {
          val.first++; val.second = w[k];
        }
        dp[i] = min(dp[i], val);
      }
    }
  }


  cout << dp[(1<<n) - 1].first;
 }
//111
