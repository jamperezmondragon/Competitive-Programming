#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const ll MOD = 1e9 + 7;
const int Mxn = 1e5 + 1;

ll binexpon(ll a, ll b, ll Mod = MOD, ll ans = 1LL) {
  for (ll i = 0; i <= 31; i++, a *= a, a %= Mod) {
    if ((b>>i)&1LL) {
      ans *= a; ans %= Mod;
    }
  }
  return ans%Mod;
}
ll inverse(ll a) {return binexpon(a, MOD - 2LL);}

ll p[Mxn], e[Mxn];

int main() {
  cin.tie(0)->sync_with_stdio(0);
  ll n; cin >> n; 
  for (ll i = 0; i < n; i++) {
    cin >> p[i] >> e[i];
  }
  ll num = 1LL;
  for (ll i = 0; i < n; i++) {
    num *= binexpon(p[i], e[i]);
    num %= MOD;
  }
  ll sum = 1LL;
  for (ll i = 0; i < n; i++) {
    sum *= binexpon(p[i], e[i] + 1LL) - 1LL;
    sum %= MOD;
    sum *= inverse(p[i] - 1LL);
    sum %= MOD;
  }
  ll divcnt = 1LL;
  for (ll i = 0; i < n; i++) {
    divcnt *= (e[i] + 1LL);
    divcnt %= MOD;
  }
  ll prod = 1LL, Divcnt = 1LL;
  for (int i = 0; i < n; i++) {
    prod = binexpon(prod, e[i] + 1);
    prod %= MOD;
    prod *= binexpon(p[i], (Divcnt*((e[i]*(e[i] + 1)/2)%(MOD - 1))%(MOD - 1)));
    prod %= MOD;
    Divcnt *= (e[i] + 1);
    Divcnt %= (MOD - 1);
  }
  cout << divcnt << " " << sum << " " << prod;
}
