#include <bits/stdc++.h>
using namespace std;
int const Mxn = 2e5 + 10;
int n, m, x, y;
vector<vector<int>> Adj(Mxn);
bool vis[Mxn];
vector<pair<int, int>> Back_Edges;
int Parent[Mxn];



void dfs(int node, int parent) {
  Parent[node] = parent;
  vis[node] = true;
  for (auto child : Adj[node]) {
    if (child == parent) continue;
    if (vis[child]) Back_Edges.push_back({node, child});
    else dfs(child, node);
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    Adj[x].push_back(y);
    Adj[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) dfs(i, 0);
  }
  if (!Back_Edges.size()) {
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  int node = Back_Edges[0].first, parent = Back_Edges[0].second;
  vector<int> ans; ans.push_back(parent);
  while (node != Parent[parent]) {
    ans.push_back(node); node = Parent[node];
  }
  cout << ans.size() << endl;
  for (auto e : ans) cout << e << " ";
}
