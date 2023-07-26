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
    int n, ans = 0; cin >> n; vi a(n);
    in(a);
    vi V; V.push_back(-1);
    for (int i = 0; i < n; i++) {
      if (a[i] == 1) V.push_back(i);
    }
    V.push_back(n);
    for (int i = 1; i < sz(V); i++) {
      ans = max(ans, V[i] - V[i - 1] - 1);
    }
    if (sz(V) == 2) ans = n;
    if (sz(V) == n + 2) ans = 0;
    cout << ans << endl;
  }
}
