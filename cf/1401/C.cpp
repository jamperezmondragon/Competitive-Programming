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
    int n; cin >> n; vi v(n); in(v);
    int m = *min_element(all(v));
    vi a;
    for (auto e : v) if (e%m == 0) a.push_back(e);
    sort(all(a));
    for (int i = 0, j = 0; i < n; i++) {
      if (v[i]%m == 0) v[i] = a[j++];
    }
    cout << (is_sorted(all(v)) ? "YES\n" : "NO\n");
  }
}
