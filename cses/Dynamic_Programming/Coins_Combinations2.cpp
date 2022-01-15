#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//debuging 
const bool DEB = false;
#define DEBUG if (DEB) 
/* Informative
* ==============
* Status: AC
* link del problema: https://cses.fi/problemset/task/1636/
* submission: https://cses.fi/problemset/result/3382732/
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
  int n, x; cin >> n >> x; int arr[n]; vector<ll> dp(x + 1);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= x; j++) {
      if (arr[i] > j) continue;
      dp[j] += dp[j - arr[i]]; dp[j] %= M;
      if (dp[j] < 0) dp[j] += M;
    }
  }
  cout << dp[x];
}
