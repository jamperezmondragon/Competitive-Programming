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
  for (ll i = 0, a = fact[Mxn - 1]; i <= 31; i++) {
    if (((MOD - 2)>>i)&1) ifact[Mxn - 1] *= a;
    ifact[Mxn - 1] %= MOD; a *= a; a %= MOD;
  }
  for (int i = Mxn - 2; i >= 0; i--) {
    ifact[i] = ifact[i + 1]*(1LL*(i + 1));
    ifact[i] %= MOD;
  }
}
ll binom(int a, int b) {
  return ((fact[a])*((ifact[b]*ifact[a - b])%MOD))%MOD;
}

int a, b;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  build();
  while (n--) {
    cin >> a >> b;
    cout << binom(a, b) << '\n';

  }
}
