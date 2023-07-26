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
  int n; cin >> n; vi a(n); in(a);
  ll ans = 0;
  ll c[32]; c[0] = 1;
  for (int i = 1; i < 32; i++) {
    c[i] = 2*c[i - 1]; c[i] %= MOD;
  }
 
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      int x = 2*a[i] - a[j];
      int y = 2*a[j] - a[i];
      int z = upper_bound(all(a), x - 1) - a.begin();
      int w = lower_bound(all(a), y) - a.begin();
      w = n - w;
      int exp = w + z;
      ll X = 1;
      for (int k = 0; k < 32; k++) {
        if ((exp>>k)&1) (X *= c[k]) %= MOD;
      }
      ans += X; ans %= MOD;
    }
  }
  cout << ans << '\n';
}
