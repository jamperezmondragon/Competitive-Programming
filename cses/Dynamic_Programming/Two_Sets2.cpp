#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//debuging 
const bool DEB = false;
#define DEBUG if (DEB) 
/* Informative
* ==============
* Status: AC
* link del problema: https://cses.fi/problemset/task/1093/
* submission: https://cses.fi/problemset/result/3386832/
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
  int n; cin >> n; ll sum = (n*(n+1))/2; 
  if (sum&1) {
    cout << 0; return 0;
  }
  sum /= 2;
  ll dp[sum + 1]; memset(dp, 0, sizeof(dp)); dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = sum; j >= i; j--) {
      dp[j] += dp[j - i]; dp[j] %= M;
    }
  }
  cout << (dp[sum]*((M + 1)/2))%M;
}
//114
