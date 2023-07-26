#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const Mxn = 2e5 + 10;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  int tt; 
  for (cin >> tt; tt; tt--) {
    ll l, r;
    cin >> l >> r;
    vector<ll> D(Mxn, 0);
    for (ll i = l; i <= r; i++) {
      for (ll j = i; j <= 2*r; j += i) D[j]++;
    }
    ll ans = (r - l + 1)*(r - l)*(r - l - 1)/6;
    for (ll i = l; i <= r; i++) {
      ans -= (D[2*i] - 2)*(D[2*i] - 3)/2;
    }
    cout << ans << endl;
  }
}
