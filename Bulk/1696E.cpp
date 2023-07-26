#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
ll const Mxn = 4e5 + 10;
ll const MOD = 1e9 + 7;
ll n; ll ans = 0;
 
ll factorial[Mxn], inv_factorial[Mxn];
 
void init() {
  factorial[0] = 1;
  for (int i = 1; i < Mxn; i++) {
    factorial[i] = (factorial[i - 1]*i)%MOD;
  }
  ll curr = factorial[Mxn - 1], b = MOD - 2; inv_factorial[Mxn - 1] = 1;
  for (int i = 0; i < 30; i++, b >>= 1) {
    if (b&1) (inv_factorial[Mxn - 1] *= curr) %= MOD;
    (curr *= curr) %= MOD;
  }
  for (int i = Mxn - 2; i > 0; i--) {
    inv_factorial[i] = (inv_factorial[i + 1]*(i + 1))%MOD;
  }
  inv_factorial[0] = 1;
}
 
ll comb(ll x, ll y) {
  return (((factorial[x]*inv_factorial[x - y])%MOD)*inv_factorial[y])%MOD;
}
 
int main() {
  cin.tie(0), ios_base::sync_with_stdio(0);
  init();
  cin >> n;
  for (int i = 0, j; i <= n; i++) {
    cin >> j; 
    if (j == 0) break;
    (ans += comb(j + i, i + 1)) %= MOD;
  }
  cout << ans << endl;
}
