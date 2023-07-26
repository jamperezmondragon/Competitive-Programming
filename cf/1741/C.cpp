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
    int n; cin >> n;
    vector<ll> a(n), psum(n + 1, 0); 
    in(a);
    for (int i = 0; i < n; i++) {
      psum[i + 1] = psum[i] + a[i];
    }
    int ans = 1e7;
    for (ll i = n; i > 0; i--) {
      if (psum[n]%i == 0) {
        ll segsum = psum[n]/i, cur = 0;
        bool flag = false; 
        int nxt = 0, prev, candi = 0;
        for (int j = 0; j < i; j++) {
          prev = nxt;
          nxt = lower_bound(psum.begin(), psum.end(), cur + segsum) - psum.begin();
          if (nxt == n + 1 || psum[nxt] != cur + segsum) {
            flag = true;
            break;
          }
          cur += segsum;
          candi = max(candi, nxt - prev);
        }
        if (flag) continue;
        if (nxt == n) ans = min(ans, candi);
      }
    }
    cout << ans << '\n'; 
  }
}
