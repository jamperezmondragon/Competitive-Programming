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
    int n; cin >> n; 
    int R = -1, C1 = -1, C2 = -1, I1 = -1, I2 = -1, L = -1;

    for (int i = 0; i < n; i++) {
      int l, r, c; cin >> l >> r >> c;

      if (R == -1) R = r, I2 = i, C2 = c;
      if (L == -1) L = l, I1 = i, C1 = c;

      if (R == r && c < C2) C2 = c, I2 = i;
      if (R < r) R = r, C2 = c, I2 = i;

      if (L == l && c < C1) C1 = c, I1 = i;
      if (L > l) L = l, C1 = c, I1 = i;

      ll ans = C1 + C2;

      if (I1 == I2) ans >>= 1;

      cout << ans << endl;
    }
  }
}
