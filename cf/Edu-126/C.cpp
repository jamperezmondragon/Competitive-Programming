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
    ll n, ans1 = 0, ans2 = 0; cin >> n;
    vl a(n); in(a); sort(all(a));

    for (int i = 0; i < n; i++) {
      ll d = a[n - 1] - a[i], x;
      if (d%3 == 0) x = d/3;
      if (d%3 == 1) x = (d - 1)/3;
      if (d%3 == 2) x = (d + 1)/3;
      ans1 += x; ans2 += d - 2*x;
    }
    cout << ans1 << " " << ans2 << endl;
  }
}
