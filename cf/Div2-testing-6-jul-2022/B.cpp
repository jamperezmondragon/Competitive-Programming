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
#define Testcase ll tt; cin >> tt; while (tt--)
#define nl "\n"
#define m_p make_pair
 
int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    int n, c, q;
    string s;
    cin >> n >> c >> q;
    vector<int> l(c), r(c), d(c);
    for (int i = 0; i < c; i++) {
      cin >> l[i] >> r[i];
      d[i] = (i == 0 ? sz(s) : d[i - 1]);
      d[i] += r[i] - l[i] + 1;
    }
    while (q--) {
      int t; cin >> t;
      while (t > sz(s)) {
        int it = lower_bound(all(d), t) - d.begin() + 1;
        t = l[it] + t - d[it];
      }
      cout << s[t - 1] << endl;
    }
  }
}
