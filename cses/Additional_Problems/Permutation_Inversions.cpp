#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int Mxn = 501;
const ll MOD = 1e9 + 7;
ll dp[Mxn][Mxn*(Mxn - 1)/2];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, k; cin >> n >> k;
  for (int i = 1; i <= n; i++) dp[i][0] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      (dp[i][j] = dp[i][j - 1] + dp[i - 1][j] - ((j >= i) ? dp[i - 1][j - i] : 0)) %= MOD;
    }
  }
  cout << (dp[n][k]%MOD + MOD)%MOD << '\n';
}
