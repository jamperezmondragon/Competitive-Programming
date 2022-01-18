#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//debuging 
const bool DEB = false;
#define DEBUG if (DEB) 
/* Informative
* ==============
* Status: AC
* link del problema: https://cses.fi/problemset/task/2413/
* submission: https://cses.fi/problemset/result/3396939/
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
  ll dp[1000005][2];
  dp[1][0] = 1; dp[1][1] = 1;
  for (int i = 1; i < 1000000; i++) {
    dp[i + 1][0] = (2*dp[i][0] + dp[i][1])%M;
    dp[i + 1][1] = (dp[i][0] + 4*dp[i][1])%M;
  }
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    cout << (dp[n][0] + dp[n][1])%M << "\n";
  }
 }
//112
