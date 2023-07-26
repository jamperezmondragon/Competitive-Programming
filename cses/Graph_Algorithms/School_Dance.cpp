#include <bits/stdc++.h>
using namespace std;
const int Mxn = 1e3 + 3;

int g[Mxn][Mxn];
bitset<Mxn> vis;
int parent[Mxn];
int n, m, k, x, y; 

bool bfs() {
  for (int i = 0; i <= n; i++) vis[i] = 0;
  vis[0] = 1;
  queue<int> Q; Q.push(0);
  while (Q.size()) {
    int i = Q.front(); Q.pop();
    for (int j = 0; j <= n; j++) {
      if (g[i][j] && !vis[j]) {
        vis[j] = 1; parent[j] = i; Q.push(j);
      }
    }
  }
  return vis[n];
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int i = 0;  i < k; i++) {
    cin >> x >> y;
    g[x][y + n] = 1;
  }
  for (int i = 1; i <= n; i++) {
    g[0][i] = 1;
  }
  for (int i = 1; i <= m; i++) {
    g[i + n][n + m + 1] = 1;
  }
  n += m + 1;
  int ans = 0;
  while (bfs()) {
    ans++;
    for (x = n; x != 0; x = parent[x]) {
      y = parent[x];
      g[y][x]--; g[x][y]++;
    }
  }
  cout << ans << '\n';
  n -= m + 1;
  for (int i = 1; i <= n; i++) {
    for (int j = n + 1; j <= n + m; j++)  {
      if (g[i][0] == 1 && g[j][i] == 1 && g[n + m + 1][j] == 1)  {
        cout << i << " " << j - n << '\n';
        break;
      }
    }
  }
}
