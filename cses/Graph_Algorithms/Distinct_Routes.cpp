#include <bits/stdc++.h>
using namespace std;
const int Mxn = 505;

int g[Mxn][Mxn];
int adj[Mxn][Mxn];
bitset<Mxn> vis;
int parent[Mxn];
int n, m, x, y;
vector<int> V;

bool bfs() {
  for (int i = 1; i <= n; i++) vis[i] = 0;
  queue<int> Q; Q.push(1); vis[1] = 1;
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
    g[x][y] = 1;
    adj[x][y] = 1;
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
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      g[i][j] ^= adj[i][j];
    }
  }
  while (bfs()) {
    V.clear();
    V.push_back(n);
    for (x = n; x != 1; x = parent[x]) {
      y = parent[x]; V.push_back(y);
      g[y][x]--; 
    }
    reverse(V.begin(), V.end());
    cout << V.size() << '\n';
    for (auto e : V) cout << e << " ";
    cout << '\n';
  }
}
