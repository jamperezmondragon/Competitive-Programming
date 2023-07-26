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
    ll n, k, ans = 0, cnt = 0; cin >> n >> k; vi a(n);
    for (int i = 0, x; i < n; i++) {
      cin >> x; ans += x; a[i] = x - (n - i - 1);
    }
    sort(all(a), greater<int>());
    for (int i = 0; i < k; i++) {
      if(a[i] + cnt < 0) break;
      ans -= a[i] + cnt; cnt++;
    }
    cout << ans << endl;
  }
}
