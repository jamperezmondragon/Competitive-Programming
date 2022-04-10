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
#define endl "\n"
#define m_p make_pair

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    int n, ans = 0; cin >> n; vi a(n); in(a); 
    vector<bool> vis(n, false);

    for (int i = 1; i < n - 1; i++) {
      if (a[i - 1] < a[i] && a[i + 1] < a[i]) {
        if (vis[i - 1]) {
          a[i - 1] = a[i]; 
        } else {
          a[i + 1] = a[i]; ans++; vis[i + 1] = true;
        }
      }
    }
    cout << ans << endl;
    for (auto e : a) cout << e << " ";
    cout << endl;
  }
}
