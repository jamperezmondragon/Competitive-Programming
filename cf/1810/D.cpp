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
    int q; cin >> q;
    ll L = 0, R = 1e18 + 1;
    while (q--) {
      int x; cin >> x;
      if (x-1) {
        ll c, s;
        cin >> c >> s;
        ll rl = 1, rh = 1; 
        if (c < R) rh = 1 + (R - s  - 1)/(c - s);
        if (c < L) rl = 1 + (L - s  - 1)/(c - s);
        if (rl == rh) cout << rh <<  ' ';
        else cout << -1 << ' ';
      } else {
        ll c, s, cl;
        cin >> c >> s >> cl;
        ll lol = 1, lor = (cl - 1)*(c - s) + c;
        if (cl != 1) lol = (cl - 2)*(c - s) + c + 1;
        if (lol <= R && L <= lor) {
          cout << 1 << ' ';
          L = max(L, lol); R = min(R, lor);
        } else cout << 0 << ' ';
      }
    }
    cout << endl;
  }
}
