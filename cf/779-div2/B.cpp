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
const ll M = 998244353;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  ll dp[1005];
  dp[0] = 1; dp[1] = 1;
  for (int i = 2; i < 1005; i++) {
    dp[i] = (i*dp[i - 1])%M;
  }
  Testcase {
    int n; cin >> n;
    if (n&1) cout << 0 << endl;
    else cout << (dp[n/2]*dp[n/2])%M << endl;
  }
}
