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
    int n, q; cin >> n >> q; vl a(n), b(n + 1, 0);
    for (int i = 0; i < n; i++) {
      cin >> a[i]; 
      b[i + 1] = b[i] + a[i];
    }
    while (q--) {
      ll l, r, k, sum = 0; cin >> l >> r >> k;
      sum = b[n] - (b[r] - b[l - 1]) + k*(r - l + 1);
      cout << ((sum&1) ? "YES\n" : "NO\n");
    }
  }
}
