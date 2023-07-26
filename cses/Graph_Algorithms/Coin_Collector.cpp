#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int Mxn = 1e5 + 1;

vector<int> g[Mxn], g_t[Mxn], Adj[Mxn];
ll Val[Mxn];
ll c[Mxn];
ll dp[Mxn];
int n, m;

namespace korasaju {
  bool vis[Mxn];
  int SCC[Mxn], cnt = 0;
  vector<int> euler;
  void dfs_euler(int node) {
    vis[node] = true;
    for (auto child : g[node]) {
      if (vis[child]) continue;
      dfs_euler(child);
    }
    euler.push_back(node);
  }
  void dfs(int node) {
    SCC[node] = cnt;
    for (auto child : g_t[node]) {
      if (SCC[child]) continue;
      dfs(child);
    }
  }
  void init() {
    for (int i = 1; i <= n; i++) {
      if (!vis[i]) dfs_euler(i);
    }
    reverse(euler.begin(), euler.end());
    for (auto e : euler) {
      if (!SCC[e]) cnt++, dfs(e);
    }
    for (int i = 1; i <= n; i++) {
      for (auto child : g[i]) {
        if (SCC[i] != SCC[child]) Adj[SCC[i]].push_back(SCC[child]);
      }
    }
  }
};


int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> Val[i];
  }
  for (int i = 0; i < m; i++) {
    int a, b; cin >> a >> b;
    g[a].push_back(b);
    g_t[b].push_back(a);
  }
  korasaju::init();
  for (int i = 1; i <= n; i++) {
    c[korasaju::SCC[i]] += Val[i];
  }
  ll ans = 0;
  for (int i = korasaju::cnt; i > 0; i--) {
    dp[i] = c[i];
    for (auto child : Adj[i]) {
      dp[i] = max(dp[i], dp[child] + c[i]);
    }
    ans = max(dp[i], ans);
  }
  cout << ans << endl;
}
