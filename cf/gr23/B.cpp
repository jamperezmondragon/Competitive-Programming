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
    int n; cin >> n; vi a(n); in (a);
    int ans = n;
    int sum = 0;
    for (int i = 0; i < n; i++) sum += a[i];
    int pref = 0;
    for (int i = 0; i < n; i++) {
      ans = min(ans, max(pref, n - i - (sum - pref)));
      pref += a[i];
    }
    ans = min(pref, ans);
    cout << ans << endl;
  }
}
