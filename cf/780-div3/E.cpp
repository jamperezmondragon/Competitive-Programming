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
    int n, ans = INT_MAX, cnt = 0; cin >> n; vi diagonals(n, 0);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        char x; cin >> x; bool val = ('1' == x);
        cnt += val; diagonals[(i - j + n)%n] += val;
      }
    }
    for (auto e : diagonals) ans = min(ans, n + cnt - 2*e);
    cout << ans << endl;
  }
}
