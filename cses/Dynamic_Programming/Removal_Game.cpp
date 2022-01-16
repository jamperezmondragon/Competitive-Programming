#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//debuging 
const bool DEB = false;
#define DEBUG if (DEB) 
/* Informative
* ==============
* Status: AC
* link del problema: https://cses.fi/problemset/task/1097
* submission: https://cses.fi/problemset/result/3386702/
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
  int n; cin >> n; vector<int> arr(n); ll dp[n][n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i; j < n; j++) {
      if (j == i) {
        dp[i][j] = ((n%2 == 1) ? arr[i] : 0);
        continue;
      }
      if ((n&1) == ((i - j + 1)&1)) {
        dp[i][j] = max(dp[i + 1][j] + arr[i], dp[i][j - 1] + arr[j]);
      } else {
        dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]);
      }
    }
  }
  cout << dp[0][n - 1];
}
//115
