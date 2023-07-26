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
#define Testcase ll tt; cin >> tt; while (tt--)
#define nl "\n"
#define m_p make_pair
 
int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    int n, q, curr = 0; cin >> n >> q;
    vi a(n); for (auto &e : a) cin >> e; vii W(n);

    for (int i = 0; i < n - 1; i++) {
      if (a[curr] > a[i + 1]) {
         W[curr].push_back(i + 1); continue;
      }
        curr = i + 1; W[curr].push_back(curr);
    }

    while (q--) {
      int x, t; cin >> x >> t; x--;
      if (a[x] == n && t >= n) {
        cout << t - n + 1 + sz(W[x]) << endl;
        continue;
      }
      if (a[x] == n) {
        cout << upper_bound(all(W[x]), t) - W[x].begin() << endl;
        continue;
      }
      cout << upper_bound(all(W[x]), t) - W[x].begin() << endl;
    }
  }
}
