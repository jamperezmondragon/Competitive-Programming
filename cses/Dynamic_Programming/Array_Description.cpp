#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//debuging 
const bool DEB = false;
#define DEBUG if (DEB) 
/* Informative
* ==============
* Status: AC
* link del problema: https://cses.fi/problemset/task/1746/
* submission: https://cses.fi/problemset/result/3396276/
*/
/*
* Comments
* =========
*/
/* Analisis
* ==========
*
*/
int const M = 1000000007;
int main() {
  int n, m; cin >> n >> m; vector<int> vec(n); ll dp[n][m + 1];
  for (auto &e : vec) cin >> e;
  memset(dp, 0, sizeof(dp));
  if (vec[0] == 0) {
    for (int i = 1; i <= m; i++) dp[0][i] = 1;
  } else {
    dp[0][vec[0]] = 1;
  }
  for (int i = 1; i < n; i++) {
    if (vec[i] != 0) {
      for (auto k : {vec[i] - 1, vec[i], vec[i] + 1}) {
        if (k > m) continue;
        dp[i][vec[i]] = (dp[i][vec[i]] + dp[i - 1][k])%M;
      }
      continue;
    }
    for (int j = 1; j <= m; j++) {
      for (auto k : {j - 1, j, j + 1}) {
        if (k > m) continue;
        dp[i][j] = (dp[i][j] + dp[i - 1][k])%M;
      }
    }
  }
  ll ans = 0;
  for (int i = 1; i <= m; i++) ans = (ans + dp[n - 1][i])%M;
  cout << ans;
}
//113
