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
    ll n, ans = 0, sum = 0; cin >> n;
    map<ll, ll> mp; bool flag = false;

    for (int i = 0, k; i < n; i++) {
      cin >> k;
      if (k == 0 && !flag) {
        ans += mp[0]; flag = true; mp.clear(); mp[0]++;
        continue;
      }
      if (k == 0 && flag) {
        ll aux = 1; sum = 0;
        for (auto [x, y] : mp) aux = max(y, aux);
        ans += aux; mp.clear();
      } else sum += k;
      mp[sum]++;
    }

    ll aux = 1; 
    for (auto [x, y] : mp) aux = max(y, aux);
    ans += aux; mp.clear();

    cout << ans << endl;
  }
}
