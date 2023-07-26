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
    int n, m, d; cin >> n >> m >> d;
    vi p(n), pos(n + 1), a(m);
    for (int i = 0; i < n; i++) {
      cin >> p[i]; pos[p[i]] = i;
    }
    for (int i = 0; i < m; i++) {
      cin >> a[i];
    }
    int ans = 1e5;
    for (int i = 0; i < m - 1; i++) {
      ans = min(max(0, pos[a[i + 1]] - pos[a[i]]), ans);
      if (pos[a[i]] + d + 1 <= m - 1) {
        ans = min(max(0, pos[a[i]] + d + 1 - pos[a[i + 1]]), ans);
      }
    }
    cout << ans << endl;
  }
}
