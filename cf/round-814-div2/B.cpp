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
    int n, k; cin >> n >> k;
    if (k&1) {
      cout << "YES" << endl;
      for (int i = 1; i <= n/2; i++) {
        cout << 2*i - 1 << ' ' << 2*i  << endl;
      }
      continue;
    }
    if (k%4 == 2) {
      cout << "YES" << endl;
      for (int i = 1; i <= n/2; i++) {
        cout << 2*i - 1 + (i&1) << ' ' << 2*i - (i&1) << endl;
      }
      continue;
    }
    else cout << "NO" << endl;
  }
}
