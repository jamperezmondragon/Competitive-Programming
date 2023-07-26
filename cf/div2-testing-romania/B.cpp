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
    int n; cin >> n; vi a(n), b(n); in(a); in(b);
    vi af(2*n + 1, 0), bf(2*n + 1, 0);
    int ca = 1, cb = 1;
    for (int i = 1; i < n; i++) {
      if (a[i - 1] != a[i]) {
        af[a[i - 1]] = max(af[a[i - 1]], ca);
        ca = 1;
      } else ca++;
      if (b[i - 1] != b[i]) {
        bf[b[i - 1]] = max(bf[b[i - 1]], cb);
        cb = 1;
      } else cb++;
    }
    af[a[n - 1]] = max(af[a[n - 1]], ca);
    bf[b[n - 1]] = max(bf[b[n - 1]], cb);
    int ans = 0;
    for (int i = 0; i <= 2*n; i++) {
      ans = max(ans, bf[i] + af[i]);
    }
    cout << ans << endl;
  }
}
