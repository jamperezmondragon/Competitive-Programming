#include <bits/stdc++.h>
using namespace std;
const int Mxn = 2e2 + 2;

int g[Mxn][Mxn], adj[Mxn][Mxn];
bitset<Mxn> vis;
int parent[Mxn];
int n, x, y;
char c;

bool bfs() {
  for (int i = 0; i < Mxn; i++) vis[i] = 0;
  queue<int> Q; vis[0] = 1; Q.push(0);
  while (Q.size()) {
    int i = Q.front(); Q.pop();
    for (int j = 0; j <= n; j++) {
      if (g[i][j] && !vis[j]) {
        parent[j] = i; vis[j] = 1; Q.push(j);
      }
    }
  }
  return vis[n];
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> c;
      if (c == 'o') {
        g[i][j + n] = adj[i][j + n] = 1;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    g[0][i] = adj[0][i] = 1;
  }
  for (int i = n + 1; i <= 2*n; i++) {
    g[i][2*n + 1] = adj[i][2*n + 1] = 1;
  }
  n += n + 1;
  int ans = 0;
  while (bfs()) {
    ans++;
    for (x = n; x != 0; x = parent[x]) {
      y = parent[x];
      g[y][x]--, g[x][y]++; 
    }
  }
  cout << ans << '\n';
  n = (n - 1)/2;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) cout << 1 << " " << i << '\n';
  }
  for (int i = n + 1; i <= 2*n; i++) {
    if (vis[i]) cout << 2 << " " << i - n << '\n';
  }
}
