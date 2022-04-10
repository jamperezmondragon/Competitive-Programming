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
    int n, m, cnt; cin >> n >> m; bool flag = false;
    char grid[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> grid[i][j];
      }
    }
    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
        cnt = 0;
        if (grid[i - 1][j - 1] == '1') cnt++;
        if (grid[i - 1][j] == '1') cnt++;
        if (grid[i][j - 1] == '1') cnt++;
        if (grid[i][j] == '1') cnt++;
        if (cnt == 3) {
          flag = true;
          break;
        }
      }
      if (flag) break;
    }
    cout << (flag ? "NO\n" : "YES\n");
  }
}
