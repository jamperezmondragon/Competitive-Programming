#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const MOD = 1e6;
int const M = MOD + 10;
int k, D;
int dp[M];

int main() {
  cin >> k >> D;
  dp[1] = 1; dp[0] = 1;
  for (int i = 2; i <= k; i++) dp[i] = (2*dp[i - 1])%MOD;
  for (int i = k + 1; i <= D; i++) {
    dp[i%M] = (2*dp[(i - 1)%M] - dp[(i - 1 - k)%M] + MOD)%MOD;
  }
  cout << dp[D%M] << endl;
}
