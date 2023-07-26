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
    vi a(n), b(n, 2*n - 1);
    for (int i = 1; i < n - 1; i++) {
      if (i&1) a[i - 1] = n - 1 - i, a[i] = 2*n - 1 - i;
      else b[i - 1] = n - 1 - i, b[i] = 2*n - 1 - i;
    }
    if (n&1) b[n - 1] = 2*n;
    else a[n - 1] = 2*n;
    a[n - 2]  = n;
    b[n - 1] = n - 1;
    for (auto e : b) cout << e << " ";
    cout << "\n";
    for (auto e : a) cout << e << " ";
    cout << "\n";
  }
}
