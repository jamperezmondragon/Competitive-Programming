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
  int n, q; cin >> n; vi a(n+1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i]; a[i] -= i;
  }
  ll ans = 0;
  vl b(n + 1), psum(n + 1, 0);

  for (int i = 1, j = 1; i <= n; i++) {
    while (j <= n && a[j] >= -i + 1) j++;
    b[i] = j - 1; psum[i] = psum[i - 1] + j - i;
    ans += j - i;
  }

  cin >> q;
  while (q--) {
    int x, y; cin >> x >> y;
    int r = max(y - x, 1);
    int l = lower_bound(all(b), x) - b.begin();
    r = max(r, l);
    ll new_ans = ans - psum[r] + psum[l];
    new_ans += (x - l + 1)*(x - l + 2)/2 - (x - r + 2)*(x - r + 1)/2;
    cout << new_ans << endl;
  }
}
