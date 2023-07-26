#include <bits/stdc++.h>
using namespace std;
const int Mxn = 5e2 + 1;


int g[Mxn][Mxn], adj[Mxn][Mxn];
bitset<Mxn> vis;
int parent[Mxn];
int n, m, x, y;

bool bfs() {
  for (int i = 1; i <= n; i++) vis[i] = 0;
  queue<int> Q; vis[1] = 1; Q.push(1);
  while (Q.size()) {
    int i = Q.front(); Q.pop();
    for (int j = 1; j <= n; j++) {
      if (g[i][j] && !vis[j]) {
        parent[j] = i; vis[j] = 1; Q.push(j);
      }
    }
  }
  return vis[n];
}



int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    adj[x][y] = g[x][y] = 1;
    adj[y][x] = g[y][x] = 1;
  }
  int ans = 0;
  while (bfs()) {
    ans++;
    for (x = n; x != 1; x = parent[x]) {
      y = parent[x];
      g[y][x]--; g[x][y]++;
    }
  }
  cout << ans << '\n';
  bfs();
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) continue;
    for (int j = 1; j <= n; j++) {
      if (adj[i][j] && !vis[j]) cout << i << " " << j << endl;
    }
  }
}
