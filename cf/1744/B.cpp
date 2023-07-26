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
    int n, q; cin >> n >> q; 
    int a = 0, b = 0; ll ans = 0;
    for (int i = 0; i < n; i++) {
      int x; cin >> x; 
      if (x&1) b++;
      else a++;
      ans += x;
    }
    while (q--) {
      int x, y; cin >> x >> y;
      if (x == 1) {
        ans += b*y;
        if (y&1) {
          a += b; b = 0;
        }
      } else {
        ans += a*y;
        if (y&1) {
          b += a; a = 0;
        }
      }
      cout << ans << endl;
    }
  }
}
