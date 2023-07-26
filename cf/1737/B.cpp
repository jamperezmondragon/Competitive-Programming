#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pi = pair<int, int>;
using vii = vector<vector<int>>;
using mii = map<int, int>;
#define in(a) for (auto &e : a) cin >> e
#define sz(x) int((x).size())
#define all(a) a.begin(), a.end()
#define ptp partition_point
#define F first
#define S second
#define Testcase ll t; cin >> t; while (t--)
#define nl "\n"
#define m_p make_pair

int const Mxn = 1e6;
int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  ll arr[Mxn]; arr[0] = 0;
  for (ll i = 1; i < Mxn; i++) {
    ll c = (ll)sqrt(i);
    arr[i] = arr[i - 1] + (i%c == 0);
  }

  Testcase {
    ll l, r; cin >> l >> r;
    ll ans = 0;
    if (l < Mxn && r < Mxn)  ans = arr[r] - arr[l - 1];
    else if (l < Mxn && r >= Mxn) {
      ans = arr[Mxn - 1] - arr[l - 1] + 3*((ll)sqrt(r) - (ll)sqrt(Mxn));
      ans++;
    } else if (l >= Mxn) {
      ans = (ll)sqrt(r) - (ll)sqrt(l - 1);
      ans *= 3;
    }
    cout << ans << endl;

  }
}
