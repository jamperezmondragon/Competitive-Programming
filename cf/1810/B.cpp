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
    if ((n&1) == 0) {
      cout << -1 << '\n';
      continue;
    }
    int x = 0, k = 1;
    while (1<<(x + 1) < n) x++;
    cout << x << endl;
    for (int i = x; i >= 1; i--) {
      if ((n>>i)&1) {
        cout << 2 << " ";
      }
      else {
        cout << 1 << " ";
      }
    }
  }
}
