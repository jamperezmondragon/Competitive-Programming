#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)a.size()
const int Mxn = 1e5 + 1;

set<int> g[Mxn];
vector<int> path;
void dfs(int node, int parent = -1) {
  if (parent != -1) g[node].erase(parent);
  while (sz(g[node])) {
    auto it = g[node].begin();
    int child = *it;
    g[node].erase(it);
    dfs(child, node);

  }
  path.push_back(node);
}

int main() {
  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b; cin >> a >> b;
    g[a].insert(b); g[b].insert(a);
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    cnt += (sz(g[i])&1);
  }
  if (cnt) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  dfs(1);
  if (sz(path) != m + 1) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  for (auto e : path) cout << e << " ";
}
