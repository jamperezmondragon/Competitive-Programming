#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//debuging 
const bool DEB = false;
#define DEBUG if (DEB) 
/* Informative
* ==============
* Status: AC
* link del problema: https://cses.fi/problemset/task/1745/
* submission: https://cses.fi/problemset/result/3386346/
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
  int n; cin >> n; vector<int> coins(n); vector<set<int>> dp(n);
  for (int i = 0; i < n; i++) {
    cin >> coins[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    dp[i].insert(coins[i]);
    if (i == n - 1) continue;
    for (auto e : dp[i + 1]) {
      dp[i].insert(e + coins[i]); dp[i].insert(e);
    }
  }
  cout << dp[0].size() << "\n";
  for (auto e : dp[0]) cout << e << " ";
}
//117
