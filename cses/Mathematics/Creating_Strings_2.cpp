#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define sz(a) (int)a.size()
const ll MOD = 1e9 + 7;
const int Mxn = 1e6 + 1;

ll fact[Mxn], inv_fact[Mxn];
int freq[26];

int main() {
  string s; cin >> s; int n = sz(s);
  fact[0] = 1;
  for (ll i = 1; i <= n; i++) {
    (fact[i] = fact[i - 1]*i) %= MOD;
  }
  inv_fact[n] = 1;
  for (ll i = 0, x = fact[n]; i <= 31; i++) {
    if (((MOD - 2)>>i)&1) {
      (inv_fact[n] *= x) %= MOD;
    }
    x *= x; x %= MOD;
  }
  for (ll i = n - 1; i >= 0; i--) {
    (inv_fact[i] = (i + 1)*inv_fact[i + 1]) %= MOD;
  }
  for (int i = 0; i < 26; i++) freq[i] = 0;
  for (auto e : s) freq[e - 'a']++;
  ll ans = fact[n];
  for (int i = 0; i < 26; i++) {
    (ans *= inv_fact[freq[i]]) %= MOD;
  }
  cout << ans << endl;
}
