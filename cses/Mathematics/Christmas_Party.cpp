#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int Mxn = 1e6 + 1;
const ll MOD = 1e9 + 7;

ll fact[Mxn], ifact[Mxn];

void build() {
  fact[0] = 1;
  for (int i = 1; i < Mxn; i++) {
    fact[i] = fact[i - 1]*(1LL*i);
    fact[i] %= MOD;
  }
  ifact[Mxn - 1] = 1;
  for (ll i = 0, a = fact[Mxn - 1]; i <= 31; i++, a *= a, a %= MOD) {
    if (((MOD - 2)>>i)&1) {
      ifact[Mxn - 1] *= a; ifact[Mxn - 1] %= MOD;
    }
  }
  for (int i = Mxn - 2; i >= 0; i--) {
    ifact[i] = ifact[i + 1]*(1LL*(i + 1));
    ifact[i] %= MOD;
  }
}



int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  build();
  ll ans = 0;
  for (int i = 0; i <= n; i++) {
    if (i&1) ans -= ifact[i];
    else ans += ifact[i];
    ans %= MOD;
  }
  ans *= fact[n];
  ans %= MOD;
  ans += MOD;
  ans %= MOD;
  cout << ans << '\n';
}
