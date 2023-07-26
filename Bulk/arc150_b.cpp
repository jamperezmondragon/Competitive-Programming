#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int tt; for (cin >> tt; tt; tt--) {
    ll a, b; cin >> a >> b;
    ll ans = ((-b)%a + a)%a;
    for (ll i = 1; i < ans; i++) {
      ans = min(ans, i + (a + i)*((b + a + i)/(a + i)) - b);
    }
    cout << ans << endl;
  }
}
