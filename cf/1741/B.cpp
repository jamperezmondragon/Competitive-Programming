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
    if (n == 3) {
      cout << -1 << endl;
      continue;
    }
    if (n == 5) {
      cout << "5 4 1 2 3" << endl;
      continue;
    }
    vi ans(n + 1);
    for (int i = 1; i <= n; i++) {
      ans[i] = n - i + 1;
    }
    if (n&1) {
      swap(ans[n/2], ans[n/2 + 1]);
    }
    for (int i = 1; i <= n; i++) {
      cout << ans[i] << " ";
    }
    cout << endl;
  }
}
