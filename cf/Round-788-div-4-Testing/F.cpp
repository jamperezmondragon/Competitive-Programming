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
    int n, k; cin >> n >> k;
    map<int, int> mp;
    for (int i = 0, x; i < n; i++) {
      cin >> x; mp[x]++;
    }
    int last = 0; map<int, int> psum;
    for (auto [x, y] : mp) {
      psum[x] += (last != 0 ? psum[last] : 0) + (y >= k ? 1 : -1);
      last = x;
    }
    last = 1; pair<int, int> ans = {0, 0};
    for (auto [x, y] : mp) {
      if (psum[x] - psum[last] == x - last  + 1) {
        if (x - last + 1 >= ans.second - ans.first) ans = {last, x};
      }
      if (psum[last] > psum[x]) last = x;
    }
    if (ans.first == 0 && ans.second == 0) {
      cout << -1 << endl; continue;
    }
    cout << ans.first << " " << ans.second << endl;
  }
}
