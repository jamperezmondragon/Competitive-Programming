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
    vector<pair<int, int>> V(n);
    for (auto &[x, y] : V) cin >> y;
    for (auto &[x, y] : V) cin >> x;
    sort(all(V));
    vector<vector<int>> A(2*n + 1);
    for (auto [x, y] : V) {
      A[y].push_back(x);
    }
    vector<vector<pair<int, ll>>> B(2*n + 1);
    for (int i = 0; i <= 2*n; i++) {
      if (sz(A[i]) == 0) continue;
      ll cnt = 1;
      for (int j = 1; j < sz(A[i]); j++) {
        if (A[i][j] != A[i][j - 1]) {
          B[i].push_back({A[i][j - 1], cnt});
          cnt = 1;
        } else cnt++;
      }
      B[i].push_back({A[i][sz(A[i]) - 1], cnt});
    }

    ll ans = 0;
    for (int x = 1; x <= 2*n; x++) {
      //cout << x << endl;
      for (int d = 1; d*d <= x; d++) {
        if (x%d != 0) continue;
        int dd = x/d;
        if (!sz(B[dd]) || !sz(B[d])) continue;
        //cout << "divisors " << dd << " " << d << endl;
        int i = 0, j = sz(B[dd]) - 1;
        ll aux = 0;
        while (i < sz(B[d]) && j >= 0) {
          //cout << "index :" << i << " " << j << endl;
          //cout << B[d][i].first << " " << B[dd][j].first << endl;
          //cout << B[d][i].second << " " << B[dd][j].second << endl;
          if (B[d][i].first + B[dd][j].first == x) {
            aux += B[d][i].second*B[dd][j].second; i++;
            continue;
          }
          if (B[d][i].first + B[dd][j].first > x) j--;
          else i++;
        }
        if (dd == d) {
          if (x&1) {
            ans += aux/2;
            continue;
          }
          for (auto [w, z] : B[dd]) if (w == x/2) aux -= z;
          ans += aux/2;
        } else ans += aux;

      }
    }
    cout << ans << endl;
  }
}
