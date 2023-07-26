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
    int n; cin >> n;
    vector<int> a, b, c;
    for (int i = 0; i < n; i++) {
      int x; string s; cin >> x >> s;
      if (s == "00") continue;
      if (s == "10") {
        a.push_back(x); continue;
      }
      if (s == "01") {
        b.push_back(x); continue;
      }
      if (s == "11") {
        c.push_back(x); continue;
      }
    }
    sort(all(a)), sort(all(b)), sort(all(c));
    int ans = -1;
    if (sz(c) && (sz(a) && sz(b))) {
      ans = min(c[0], b[0] + a[0]); 
      cout << ans << endl; continue;
    }
    if (!sz(c) && (sz(a) && sz(b))) {
      ans = a[0] + b[0]; cout << ans << endl; continue;
    }
    if (sz(c)) ans = c[0];
    cout << ans << endl;
  }
}
