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
const int MOD = 1e9 + 7; 
int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    int n, q; cin >> n >> q; vi a(n); in(a);
    vector<vector<ll>> dp(64, vector<ll>(n, 0));
    dp[a[0]][0] = 1;
    for (int i = 1; i < n; i++) {
      dp[a[i]][i] = 1;
      for (int j = 0; j < 64; j++) {
        (dp[j][i] += dp[j][i - 1]) %= MOD;
        (dp[j&a[i]][i] += dp[j][i - 1]) %= MOD;
      }
    }
    ll ans = 0;
    for (int i = 0; i < 64; i++) {
      if (__builtin_popcount(i) == q) (ans += dp[i][n - 1]) %= MOD;
    }
    cout << ans << endl;
  }
}
