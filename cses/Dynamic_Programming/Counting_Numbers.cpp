#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
#define sz(a) (int)a.size()

ll expon(ll a, ll b, ll ans = 1) {
  for (int i = 0; i < b; i++) ans *= a;
  return ans;
}
auto pref(ll x) -> ll {
  if (x < 10) return x;
  vector<int> D; ll ans = 0;
  for (ll i = x; i; i /= 10) D.push_back(i%10); 

  for (int i = 1; i < sz(D); i++) ans += expon(9, i);

  D.push_back(-1);
  for (ll i = sz(D) - 2; i >= 0; i--) {
    ans += D[i]*expon(9, i);
    if (D[i + 1] < D[i]) ans -= expon(9, i);
    if (D[i + 1] == D[i]) break;
  }
  for (int i = 1; i < sz(D); i++) {
    if (D[i] == D[i - 1]) return ans;
  }
  return ans + 1;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  ll a, b; cin >> a >> b;
  cout << pref(b) - pref(a - 1) << '\n';
}
