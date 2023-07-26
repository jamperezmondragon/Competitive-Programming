#include <bits/stdc++.h>
using namespace std;
const int Mxn = 1e5 + 1;

vector<int> g[Mxn], g_t[Mxn];
vector<int> euler;
bool vis[Mxn];
int SCC[Mxn];

void dfs_euler(int node) {
  vis[node] = true;
  for (auto child : g[node]) {
    if (vis[child]) continue;
    dfs_euler(child);
  }
  euler.push_back(node);
}
void dfs_SCC(int node, int val) {
  SCC[node] = val;
  for (auto child : g_t[node]) {
    if (SCC[child] != 0) continue;
    dfs_SCC(child, val);
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m, a, b, cnt = 0; cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    g[a].push_back(b);
    g_t[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) dfs_euler(i);
  }
  reverse(euler.begin(), euler.end());
  for (auto e : euler) {
    if (!SCC[e]) dfs_SCC(e, ++cnt);
  }
  cout << cnt << endl;
  for (int i = 1; i <= n; i++) {
    cout << SCC[i] << " ";
  }
}
