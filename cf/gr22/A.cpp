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
    int n; cin >> n; vi a(n); in(a);
    vector<int> A[2];
    for (int i = 0; i < n; i++) {
      int x; cin >> x; A[a[i]].push_back(x);
    }
    sort(all(A[0]), greater<int>());
    sort(all(A[1]), greater<int>());
    int i = 0, j = 0; ll ans = 0;

    while (i < sz(A[0]) && j < sz(A[1])) {
      ans += 2*(A[0][i++] + A[1][j++]);
    }
    if (i == sz(A[0]) && j == sz(A[1])) {
      ans -= min(A[0].back(), A[1].back());
    }
    if (i == sz(A[0]) && j < sz(A[1])) {
      while (j < sz(A[1])) ans += A[1][j++];

    } else if (j == sz(A[1]) && i < sz(A[0])) {
      while (i < sz(A[0])) ans += A[0][i++];

    }


    cout << ans << endl;
 
  }
}
