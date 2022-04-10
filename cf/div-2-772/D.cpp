#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
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
int const M = 1e9+7;
int const Mx = 2e5+10;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  vector<ll> dp(Mx); dp[0] = 1; dp[1] = 2;
  for (int i = 2; i < Mx; i++) {
    dp[i] = (2*dp[i - 1] + dp[i - 2])%M;
  }
  Testcase {
    int n, p; cin >> n >> p; vector<pii> a(n);
    for (int i = 0; i < n; i++)  {
      cin >> a[i].second; a[i].first = msb(a[i]);
    }
    sort(all(a)); reverse(all(a));
    for (int i = 0; i < n; i++) {
      int MSB = a[i].first, x = a[i].second;
      if (p < 32 && x > 1<<p) continue;
      // inicializar curr;
      for (int k = MSB - 1; k >= 0; k--) {
        if (flag) create(curr, x&(1<<k));
        else move(curr, x&(1<<k));
        if (flag) continue;
        if (curr == NULL && barrido(x, k)) break;
        else flag = true;
        if (k == 0) (ans += dp[p - MSB]) %= M;
      }
    }
    cout << ans << endl;
  }
}
