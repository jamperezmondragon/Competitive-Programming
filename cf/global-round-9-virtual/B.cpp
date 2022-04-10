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
    int n, m; cin >> n >> m; bool flag = true;
    int g[n + 2][m + 2];
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cin >> g[i][j]; 
        int val = 4 - (i == 1 || i == n) - (j == 1 || j == n);
        if (g[i][j] > val) flag = false;
        else g[i][j] = val;
      }
    }
    if (!flag) {
      cout << "NO" << endl; continue;
    }
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        cout << g[i][j] << " "; 
      }
      cout << endl;
    }
  }
}
