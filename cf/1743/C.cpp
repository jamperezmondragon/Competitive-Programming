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
 
int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    ll n; cin >> n; 
    multiset<ll> S;
    vl a(n);
    string s; cin >> s;
    in(a);
    ll ans = 0;
    for (ll i = n - 1; i >= 0; i--) {
      if (s[i] == '1') {
        S.insert(a[i]); ans += a[i];
      } else {
        if (sz(S) && *S.begin() < a[i]) {
          ans -= *S.begin(); ans += a[i];
          S.erase(S.begin()); S.insert(a[i]);
        }
      }
    }
    cout << ans << endl;
  }
}
