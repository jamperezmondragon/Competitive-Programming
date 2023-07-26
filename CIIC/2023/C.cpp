#include <bits/stdc++.h>
using namespace std;

bitset<2000000> T;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m; cin >> n >> m;
  vector<vector<int>> grid(n, vector<int>(m));
  vector<int> vals(n, 0);

  int cnt = m - 1;
  for (int i = 0; i < n; i++) {
    int aux = 0;
    for (int j = 0; j < m; j++) {
      cin >> grid[i][j];
      if (grid[i][j] != 0) aux = j;
    }
    cnt = min(aux, cnt);
  }

  if (cnt == m - 1) {
    for (int i = 1; i < m; i++) cout << 0 << " ";
    cout << 1 << endl;
    return 0;
  }

  for (int i = 0; i < n; i++) {
    for (int j = cnt; j < m - 1; j++) {
      vals[i] += grid[i][j];
    }
    if (vals[i]%grid[i][m - 1] != 0) continue;
    if (vals[i] == 0)
  }
}
