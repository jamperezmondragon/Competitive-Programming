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
    int n; cin >> n; string s; cin >> s;
    s += 'a'; int curr = 1; vi vals;
    for (int i = 1; i <= n; i++) {
      if (s[i] == s[i - 1]) curr++;
      else {
        vals.push_back(curr); curr = 1;
      }
    }
    int ans = 0, last = -1, ans2 = 0;
    for (int i = 0; i < sz(vals); i++) {
      if (last != -1 && vals[i] <= 2) ans2++;
      if (!(vals[i]&1)) continue;
      if (last == -1) {
        last = i; continue;
      }
      ans += i - last; last = -1;
    }
    cout << ans << " " << sz(vals) - ans2 << nl;
  }
  //Testcase {
    //int n; cin >> n; string s; cin >> s;
  //}
}
