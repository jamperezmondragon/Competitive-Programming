#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)a.size()
const int Mxn = 1e5 + 1;

bitset<Mxn> vis;
int depth[Mxn], deg[Mxn];
vector<int> g[Mxn];
int n, m, x, y;
vector<pair<int, int>> A;

void dfs(int node, int parent = 0) {
  vis[node] = 1;
  depth[node] = depth[parent] + 1;
  for (auto child : g[node]) {
    if (child == parent) continue;
    if (vis[child]) {
      if (depth[child] < depth[node]) {
        A.push_back({node, child});
        deg[node]++;
      }
    } else {
      dfs(child, node);
      if (deg[child]&1) {
        A.push_back({child, node});
        deg[child]++;
      } else {
        A.push_back({node, child});
        deg[node]++;
      }
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  bool flag = true;
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    x = sz(A); dfs(i); x -= sz(A);
    if (x&1) flag = false;
  }
  if (flag) {
    for (auto [z, w] : A) {
      cout << z << " " << w << '\n'; 
    }
  } else {
    cout << "IMPOSSIBLE\n";
  }
}
