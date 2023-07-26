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
    int n, m; cin >> n >> m;
    vector<int> a(n + 1, 0);
    for (int i = 0; i < m; i++) {
      int x, y; cin >> x >> y;
      a[x]++, a[y]--;
    }
    for (int i = 1; i <= n; i++) {
      a[i] = a[i] + a[i - 1];
    }
    ll ans = 0;
    for (int i = 1, j = 1; i <= n; i++) {
      if (i == j) j++;
      while (j <= n && a[j] >= a[j - 1]) j++;
      ans += j - i;
    }
    cout << ans << endl;
  }
}
