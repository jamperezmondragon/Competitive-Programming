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
    vector<int> V(1001, -1);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
      int x; cin >> x; V[x] = i;
    }
    int ans = -1;
    for (int i = 1; i <= 1000; i++) {
      if (V[i] == -1) continue;
      for (int j = 1; j <= 1000; j++) {
        if (V[j] == -1) continue;
        if (__gcd(i, j) == 1) ans = max(V[i] + V[j], ans);
      }
    }
    cout << ans << endl;
  }
}
