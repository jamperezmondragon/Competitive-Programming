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
  vector<ll> dp(2023*1012 + 1, -1);
  vector<ll> psum(2023*1012 + 1, 0);
  for (ll i = 1; i <= 2023; i++) {
    ll x = (i*i + i)/2;
    dp[x] = x*x + ((i == 1) ? 0 : dp[x - i]);
  }
  cout << endl;
  for (ll i = 1; i < 2023; i++) {
    for (ll j = -i, k = 1; j <= 2023*1012; j += k, k++)  {
      if (j <= 0) continue;
      if (dp[j] != -1) continue;
      if (j <= k - 1) psum[j] = j*j;
      else psum[j] = j*j + psum[j - k + 1];
      dp[j] = dp[j - k + 2] + psum[j];
    }
    cout << endl;
  }
  Testcase {
    int n; cin >> n;
    cout << dp[n] << endl;
  }
}
