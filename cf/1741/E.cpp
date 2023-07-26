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
    int n; cin >> n; vector<int> dp(n + 1, 0);
    vi a(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
      if (i - a[i] > 0) dp[i] |= dp[i - a[i] - 1];
      if (i + a[i] <= n) dp[i + a[i]] |= dp[i - 1];
    }
    cout << ((dp[n]) ? "YES\n" : "NO\n");
  }
}
