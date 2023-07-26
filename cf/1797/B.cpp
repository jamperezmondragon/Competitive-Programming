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
    vii g(n, vector<int>(n, 0));
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> g[i][j];
      }
    }
    vii p(n, vector<int>(n, 0));
    vii q(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        p[i][j] = g[j][n - i - 1];
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        q[i][j] = p[j][n - i - 1];
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cnt += (g[i][j] != q[i][j]);
      }
    }
    cnt >>= 1;
    if ((n&1) && cnt <= k) cout << "YES\n";
    else if (cnt <= k && ((cnt&1) == (k&1))) cout << "YES\n";
    else cout << "NO\n";
  }
}
