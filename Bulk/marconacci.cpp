#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const Mxn = 1e6 + 5;
int const MOD = 1e9 + 7;

ll dp[Mxn];

int main() {
  dp[1] = 1;
  for (int i = 1; i + 2 < Mxn; i++) {
    (dp[i + 1] += dp[i]) %= MOD; (dp[i + 2] += dp[i]) %= MOD;
  }
  int q; cin >> q;

  while (q--) {
    ll a, b, i; cin >> a >> b >> i;
    if (i == 1) {
      cout << a << endl; continue;
    }
    if (i == 2) {
      cout << b << endl; continue;
    }
    ll ans = (b*dp[i - 1] + a*dp[i - 2])%MOD;
    cout << ans << endl;
  }
}
