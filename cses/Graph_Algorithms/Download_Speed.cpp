#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int Mxn = 5e2 + 1;

ll g[Mxn][Mxn];
bitset<Mxn> vis;
int parent[Mxn];
int n, m, x, y, z;
ll maxflow = 0, flow = 1e18;

bool bfs() {
  for (int i = 0; i < Mxn; i++) vis[i] = 0;
  queue<int> Q;
  Q.push(1); vis[1] = 1;
  while (Q.size()) {
    int node = Q.front(); Q.pop();
    for (int i = 1; i <= n; i++) {
      if (g[node][i] && !vis[i]) {
        vis[i] = 1; parent[i] = node; Q.push(i);
      }
    }
  }
  return vis[n];
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> x >> y >> z;
    g[x][y] += z;
  }
  while (bfs()) {
    flow = 1e18;
    for (x = n; x != 1; x = parent[x]) {
      y = parent[x];
      flow = min(g[y][x], flow);
    }
    maxflow += flow;
    for (x = n; x != 1; x = parent[x]) {
      y = parent[x];
      g[y][x] -= flow;
      g[x][y] += flow;
    }
  }
  cout << maxflow << '\n';
}
