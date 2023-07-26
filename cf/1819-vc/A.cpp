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
    int n; cin >> n; vi a(n);
    in(a);
    vector<int> f(n + 1, 0);
    for (auto e : a) {
      if (e > n) continue;
      f[e]++;
    }
    int mex = 0;
    while (f[mex] > 0) mex++;
    if (mex == n) {
      cout << "NO\n";
      continue;
    } 
    if (f[mex + 1] <= 1) {
      cout << "YES\n";
      continue;
    }
    int l = -1, r = -1;
    for (int i = 0; i < n; i++) {
      if (a[i] != mex + 1) continue;
      if (l == -1) l = i;
      else r = i;
    }
    f.assign(n + 1, 0);
    for (int i = 0; i < n; i++) {
      if (l <= i && i <= r) continue;
      if (a[i] > n) continue;
      f[a[i]]++;
    }
    int new_mex = 0;
    while (f[new_mex] > 0) new_mex++;
    if (new_mex == mex) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
