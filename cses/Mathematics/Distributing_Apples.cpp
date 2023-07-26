#pragma GCC optimize("unroll-loops", "O3")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const ll MOD = 1e9 + 7;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  ll n, m, ans = 1; cin >> n >> m;
  ll a = m + n - 1, b = n - 1, x = 1;
  for (int i = a - b + 1; i <= a; i++) {
    ans *= i*1LL; ans %= MOD;
  }
  for (int i = 1; i <= b; i++) {
    x *= 1LL*i; x %= MOD;
  }
  for (int i = 0; i <= 31; i++) {
    if (((MOD - 2)>>i)&1) {
      ans *= x; ans %= MOD;
    }
    x *= x; x %= MOD;
  }
  cout << ans << '\n';
}
