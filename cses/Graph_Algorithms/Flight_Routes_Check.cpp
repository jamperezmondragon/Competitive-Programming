#include <bits/stdc++.h>
using namespace std;
const int Mxn = 2e5 + 1;
int cnt = 0, cntr = 0;

void dfs(int node, vector<vector<int>> & adj, int & c, vector<bool> & v) {
  c++; v[node] = true;
  for (auto child : adj[node]) {
    if (v[child]) continue;
    dfs(child, adj, c, v);
  }
}

int main() {
  int n, m; cin >> n >> m; 
  vector<vector<int>> g, r;
  g.assign(n + 1, {}); r.assign(n + 1, {});
  for (int i = 0; i < m; i++) {
    int x, y; cin >> x >> y;
    g[x].push_back(y); r[y].push_back(x);
  }
  vector<bool> vis(n + 1), visr(n + 1);
  dfs(1, g, cnt, vis);
  dfs(1, r, cntr, visr);
  if (cnt == cntr && cnt == n) {
    cout << "YES\n"; return 0;
  }
  cout << "NO\n";
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    cout << "1 " << i << '\n'; return 0;
  }
  for (int i = 1; i <= n; i++) {
    if (visr[i]) continue;
    cout << i << " 1\n"; return 0;
  }

}
