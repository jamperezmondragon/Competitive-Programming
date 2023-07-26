#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const ll MOD = 1e9 + 7;

ll binexpon(ll a, ll b, ll ans = 1)  {
  for (int i = 0; i <= 31; i++) {
    if ((b>>i)&1) {
      ans *= a; ans %= MOD;
    }
    a *= a; a %= MOD;
  }
  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  if (n&1) {
    cout << 0 << '\n';
  } else {
    ll ans = 1, x = 1;
    for (int i = n/2 + 2; i <= n; i++) {
      ans *= 1LL*i; ans %= MOD;
    }
    for (int i = 1; i <= n/2; i++) {
      x *= 1LL*i; x %= MOD;
    }
    x = binexpon(x, MOD - 2);
    ans *= x; ans %= MOD; ans += MOD; ans %= MOD;
    cout << ans << '\n';
  }

}
