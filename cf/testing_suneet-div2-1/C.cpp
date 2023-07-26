#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define in(a) for (auto &e : a) cin >> e
#define sz(x) int((x).size())
#define all(a) a.begin(), a.end()
#define Testcase ll t; cin >> t; while (t--)

 
int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    int n, m; cin >> n >> m;
    bool flag = false;
    if (n == 4) swap(n, m), flag = true;
    int grid[n + 1][m + 1];
    int c = 0;
    for (int i = 1; i <= n; i += 2) {
      for (int j = 1; j <= m; j++) {
        grid[i][j] = ++c;
      }
    }
    for (int i = 2; i <= n; i += 2) {
      for (int j = 1; j <= m; j++) {
        grid[i][j] = ++c;
      }
    }
    if (!flag) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
          cout << grid[i][j] << " ";
        }
        cout << '\n';
      }
    } else {
      for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
          cout << grid[j][i] << " ";
        }
        cout << '\n';
      }
    }
  }
}
