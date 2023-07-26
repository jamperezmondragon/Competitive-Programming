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
    int n, s1, s2; cin >> n >> s1 >> s2;
    vi a, b; vector<pair<int, int>> A;
    for (int i = 0; i < n; i++) {
      int x; cin >> x;
      A.push_back({x, i});
    }
    sort(A.rbegin(), A.rend());

    int i = 0;
    while (sz(a) + sz(b) < n) {
      if ((sz(a) + 1)*s1 < (sz(b) + 1)*s2) {
        a.push_back(A[i++].second + 1);
      } else {
        b.push_back(A[i++].second + 1);
      }
    }
    cout << sz(a) << ' ';
    for (auto e : a) cout << e << ' ';
    cout << '\n';
    cout << sz(b) << ' ';
    for (auto e : b) cout << e << ' ';
    cout << '\n';
  }
}
