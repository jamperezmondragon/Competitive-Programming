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
    int n; cin >> n; vi a(n); in(a); bool flag = false;
    int last = INT_MAX, ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        while (last <= a[i]) {
            a[i] /= 2; ans++;
        }
        if (a[i] == 0 && i > 0) {
          flag = true; break;
        }
        last = a[i];
    }
    if (flag) {
      cout << -1 << nl; continue; 
    }
    cout << ans << nl;
  }
}
