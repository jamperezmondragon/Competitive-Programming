#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const ll Mxn = 5e3 + 1;
const ll INF = 1e17;

ll dist[Mxn], par[Mxn];

struct Edge {ll a, b, w;};

vector<int> Adj[Mxn];
vector<bool> vis;

int dfs(int node) { 
  vis[node] = true; int ans = node;
  for (auto child : Adj[node]) {
    if (!vis[child]) ans = max(ans, dfs(child));
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m; cin >> n >> m;

  for (int i = 1; i <= n; i++) dist[i] = -INF;
  dist[1] = 0;

  vector<Edge> Edges(m);
  for (auto &[a, b, w] : Edges) cin >> a >> b >> w;
  for (auto [a, b, w] : Edges) Adj[a].push_back(b);
  vector<ll> V;

  for (int i = 0; i < n; i++) {
    for (auto [a, b, w] : Edges) {
      if (dist[a] == -INF) continue;
      if (dist[a] + w > dist[b]) {
        if (i == n - 1) V.push_back(b);
        dist[b] = dist[a] + w;
      }
    }
  }

  bool flag = false;
  for (auto e : V) {
    if (dist[e] == -INF) continue;
    vis.assign(n + 1, false); 
    if (dfs(e) == n) flag = true;
  }
  
  cout << ((flag) ? -1 : dist[n]) << '\n';

}
