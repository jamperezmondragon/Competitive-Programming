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
    int n, ans = 0; string s; cin >> n >> s;
    vector<int> v(n + 1, -1); int cnt = n;
    for (int i = 1; i <= n; i++) {
      if (s[i - 1] == 'L') ans += i - 1, v[i] = n - 2*i + 1;
      else ans += n - i, v[i] = 2*i - n - 1;
    }
    sort(v.begin(), v.end());
    for (int i = 0; i <= n; i++) {
      if (v[i] >= 0) {
        ans += v[i]; cout << ans << " "; cnt--;
      }
    }
    for (int i = 0; i < cnt; i++) cout << ans << " ";
    cout << endl;
  }
}
