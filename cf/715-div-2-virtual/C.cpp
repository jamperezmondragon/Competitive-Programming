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
#define endl "\n"
#define m_p make_pair

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  int n; cin >> n; vl a(n); in(a); sort(all(a));
  ll dp[2005][2005];
  for (int k = 0; k < n; k++) {
    for (int i = 0; i + k < n; i++) {
      if (k == 0) {
        dp[i][i] = 0; continue;
      }
      dp[i][i + k] = 
        min(dp[i + 1][i + k], dp[i][i + k - 1]) + a[i + k] - a[i];
    }
  }
  cout << dp[0][n - 1];
}
