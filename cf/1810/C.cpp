#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pi = pair<int, int>;
using vii = vector<vector<int>>;
using mii = map<int, int>;
#define in(a) for (auto &e : a) cin >> e
#define sz(x) ll((x).size())
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
    ll n, c, d, ans = 0, ahuevo = 0; cin >> n >> c >> d; vi a(n);
    in(a);
    map<int, int> cc;
    for (auto e : a) cc[e]++;
    a.clear();
    for (auto &[x, y] : cc) {
      if (y > 1) ahuevo += c*(y - 1);
      a.push_back(x);
    }
    ans = n*c + d;
    for (int i = sz(a) - 1; i >= 0; i--) {
      ans = min(ans, ahuevo + ((sz(a) - 1) - i)*c + d*(a[i] - i - 1));
    }
    cout << ans << endl;
  }
}
