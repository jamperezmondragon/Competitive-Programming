#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int Mxn = 1e5 + 1;
const ll MOD = 2038074743;
const ll INF = 1e17;

vector<pair<int, ll>> g[Mxn], g_t[Mxn];
ll dist[2][Mxn], dp[2][Mxn];

struct dijkstra_obj {
  int node; ll W;
  bool operator<(const dijkstra_obj & A) const {return W > A.W;}
};

void dijkstra0(int src) {
  for (int i = 0; i < Mxn; i++) dist[0][i] = INF, dp[0][i] = 0;
  dist[0][src] = 0;
  dp[0][src] = 1;
  priority_queue<dijkstra_obj> Q; Q.push({src, 0});
  while (Q.size()) {
    auto [node, W] = Q.top(); Q.pop();
    if (dist[0][node] != W) continue;
    for (auto [child, w] : g[node]) {
      if (dist[0][child] < W + w) continue;
      if (dist[0][child] == W + w) {
        (dp[0][child] += dp[0][node]) %= MOD;
      } else {
        dp[0][child] = dp[0][node];
        dist[0][child] = W + w;
        Q.push({child, dist[0][child]});
      }
    }
  }
}

void dijkstra1(int src) {
  for (int i = 0; i < Mxn; i++) dist[1][i] = INF, dp[1][i] = 0;
  dist[1][src] = 0;
  dp[1][src] = 1;
  priority_queue<dijkstra_obj> Q; Q.push({src, 0});
  while (Q.size()) {
    auto [node, W] = Q.top(); Q.pop();
    if (dist[1][node] != W) continue;
    for (auto [child, w] : g_t[node]) {
      if (dist[1][child] < W + w) continue;
      if (dist[1][child] == W + w) {
        (dp[1][child] += dp[1][node]) %= MOD;
      } else {
        dp[1][child] = dp[1][node];
        dist[1][child] = W + w;
        Q.push({child, dist[1][child]});
      }
    }
  }
}

int main() {
  int n, m, x, y, w; cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> x >> y >> w;
    g[x].push_back({y, w});
    g_t[y].push_back({x, w});
  }
  dijkstra0(1);
  dijkstra1(n);
  vector<int> V;
  for (int i = 1; i <= n; i++) {
    if (dist[0][i] + dist[1][i] == dist[0][n] && (dp[0][i]*dp[1][i])%MOD == dp[0][n]) V.push_back(i);
  }
  cout << V.size() << endl;
  for (auto e : V) cout << e << " ";
}
