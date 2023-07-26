#include <bits/stdc++.h>
using namespace std;
const int Mxn = 2e5 + 2;
bitset<Mxn> vis, coso;
int SCC[Mxn];
vector<int> euler, g[Mxn], g_t[Mxn];

void dfs_euler(int node) {
  vis[node] = 1;
  for (auto child : g[node]) {
    if (vis[child]) continue;
    dfs_euler(child);
  }
  euler.push_back(node);
}

void dfs(int node, int c) {
  coso[node] = 1; SCC[node] = c;
  for (auto child : g_t[node]) {
    if (coso[child]) continue;
    dfs(child, c);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int x, y, n, m; cin >> m >> n;
  char c, s;
  for (int i = 0; i < m; i++) {
    cin >> c >> x >> s >> y;
    x = 2*x + ((c == '+') ? 1 : 0);
    y = 2*y + ((s == '+') ? 1 : 0);
    g[x^1].push_back(y);
    g[y^1].push_back(x);
    g_t[x].push_back(y^1);
    g_t[y].push_back(x^1);
  }
  for (int i = 2; i <= 2*n + 1; i++) {
    if (!vis[i]) dfs_euler(i);
  }
  reverse(euler.begin(), euler.end());
  int cnt = 2*n;
  for (auto e : euler) {
    if (!coso[e]) dfs(e, cnt--);
  }
  vector<char> S;
  bool flag = true;
  for (int i = 1; i <= n; i++) {
    if (SCC[2*i] == SCC[2*i + 1]) flag = false;
    else {
      if (SCC[2*i] < SCC[2*i + 1]) S.push_back('-');
      else S.push_back('+');
    }
  }
  if (flag) {
    for (auto e : S) cout << e << " ";
  } else {
    cout << "IMPOSSIBLE\n";
  }
}
