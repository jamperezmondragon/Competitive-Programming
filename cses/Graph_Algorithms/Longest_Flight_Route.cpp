#include <bits/stdc++.h>
using namespace std;
const int Mxn = 1e5 + 2;

vector<int> topo;
vector<vector<int>> Adj;
int vis[Mxn], dp[Mxn], p[Mxn];

int dfs(int node, int ans = 1) {
  if (vis[node] == 1) return 0;
  vis[node] = 1;
  for (auto child : Adj[node]) {
    if (vis[child] == 2) continue;
    ans &= dfs(child);
  }
  topo.push_back(node);
  vis[node] = 2;
  return ans;
}

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  int n, m; cin >> n >> m;
  Adj.assign(n + 1, {});
  for (int i = 0; i < m; i++) {
    int x, y; cin >> x >> y;
    Adj[x].push_back(y);
  }
  int flag = 1;
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    flag &= dfs(i);
  }
  if (!flag) {
    cout << "IMPOSSIBLE\n"; return 0;
  }
  for (auto e : topo) {
    dp[e] = (e == n ? 1 : -Mxn);
    p[e] = e;
    for (auto child : Adj[e]) {
      if (dp[e] < dp[child] + 1) p[e] = child;
      dp[e] = max(dp[e], dp[child] + 1);
    }
  }
  if (dp[1] < 0) {
    cout << "IMPOSSIBLE\n"; return 0;
  }
  cout << dp[1] << '\n';
  int x = 1;
  while (x != n) {
    cout << x << " "; x = p[x];
  }
  cout << n << '\n';

}
