#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//debuging 
const bool DEB = false;
#define DEBUG if (DEB) 
/* Informative
* ==============
* Status: AC
* link: https://cses.fi/problemset/result/3382490/
*/
/*
* Comments
* =========
*/
/* Analisis
* =========================
*
*/
int const M = 1000000007;
int main() {
  int n; cin >> n; char grid[n][n]; ll dp[n][n];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      dp[i][j] += ((i == 0) ? 0 : dp[i - 1][j]);
      dp[i][j] += ((j == 0) ? 0 : dp[i][j - 1]);
      dp[i][j] %= M;
      if (grid[i][j] == '*')  dp[i][j] = 0;
    }
  }
  cout << dp[n - 1][n - 1];
}
