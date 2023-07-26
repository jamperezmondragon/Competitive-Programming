#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const Mxn = 1<<18;
int const MOD = 998244353;  
int n; 
string S[Mxn];
ll dp[Mxn];

void dfs(int i = 1) {
  if (i<<1 > 1<<n) {
    dp[i] = 1; return;
  }
  dfs(i<<1); dfs(i<<1|1);
  if (S[i<<1] == S[i<<1|1]) {
    dp[i] = (dp[i<<1]*dp[i<<1])%MOD;
  } else {
    dp[i] = (2*dp[i<<1]*dp[i<<1|1])%MOD;
  }
  S[i] += min(S[i<<1] + S[i<<1|1], S[i<<1|1] + S[i<<1]);
}

int main() {
  cin >> n;
  for (int i = 1; i < (1<<n); i++) {
    char x; cin >> x; S[i] += x;
  }
  dfs();
  cout << dp[1] << endl;
}
