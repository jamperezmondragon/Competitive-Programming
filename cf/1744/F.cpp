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
    int n; cin >> n; vi a(n); in(a);
    vi b(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      b[a[i]] = i;
    }
    int l = b[0], r = b[0];
    for (int i = 0; i < n; i++) {
      l = min(b[i], l), r = max(b[i], r);
      int x = l - r + 1;
      int y = 2*(i + 1);
      y--;

      int c = max(0, r - y + 1), d = min(n - 1, l + y - 1);

      ans += max(0, (d - c + 2) - y);

      y++;
      c = max(0, r - y + 1), d = min(n - 1, l + y - 1);
      ans += max(0, (d - c + 2) - y);
    }
    cout << ans << endl;
  }
}
