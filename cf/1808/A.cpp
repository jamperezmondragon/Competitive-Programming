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
    int l, r; cin >> l >> r;
    int aux = -1, ans = -1;
    for (int i = l; i <= min(l + 200, r); i++) {
      int mi = 10, ma = -1, a = i;
      while (a) {
        int x = a%10; mi = min(x, mi), ma = max(x, ma);
        a /= 10;
      }
      if (aux < ma - mi) {
        ans = i; aux = ma - mi;
      }
    }
    cout << ans << endl;
  }
}
