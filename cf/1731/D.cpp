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
    int n, m; cin >> n >> m;
    ll a[n + 1][m + 1];
    ll b[n + 1][m + 1];
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> a[i][j];
      }
    }
    int L = 1, R = min(n, m);
    while (L < R) {
      ll M = (L + R + 1)/2;
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          b[i][j] = (a[i][j] >= M);
        }
      }
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
        }
      }
      int flag = 0; 
      for (int i = M; i <= n; i++) {
        for (int j = M; j <= m; j++) {
          flag |= (b[i][j] - b[i - M][j] - b[i][j - M] + b[i - M][j - M] == M*M);
        }
      }
      if (flag) L = M;
      else R = M - 1;
    }
    cout << L << endl;
  }
}
