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
  int n, q, x; cin >> n >> q; vi a(n), psum(n, 0);
  for (auto &e : a) cin >> e;
  sort(all(a)); reverse(all(a));
  psum[0] = a[0];
  for (int i = 1; i < n; i++) {
    psum[i] = psum[i - 1] + a[i];
  }
  while (q--) {
    cin >> x;
    int it = lower_bound(all(psum), x) - psum.begin() + 1;
    cout << (it > n ? -1 : it) << endl;
  }
}
