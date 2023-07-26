#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int Mxn = 1e5 + 1;
const ll INF = 1e17;
const ll MOD = 1e9 + 7;

ll dist[Mxn];
int indegree[Mxn];
ll dp[Mxn];
vector<int> g[Mxn];
vector<pair<int, ll>> Adj[Mxn];

struct dijkstra_obj {
  int node; ll w; 
  bool operator<(const dijkstra_obj & A) const {return w > A.w;}
};

void dijkstra(int src = 1) {
  for (int i = 1; i < Mxn; i++) dist[i] = INF;
  priority_queue<dijkstra_obj> pq;
  dist[src] = 0; pq.push({src, 0});
  while (pq.size()) {
    auto [node, W] = pq.top(); pq.pop();
    if (dist[node] != W)  continue;
    for (auto [child, w] : Adj[node]) {
      if (dist[child] > dist[node] + w) {
        dist[child] = dist[node] + w;
        pq.push({child, dist[child]});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y, w; cin >> x >> y >> w;
    Adj[x].push_back({y, w});
  }
  for (int i = 1; i <= n; i++) indegree[i] = 0;
  dijkstra();
  cout << dist[n] << " ";

  for (int i = 1; i <= n; i++) {
    if (dist[i] == INF) continue;
    for (auto [child, w] : Adj[i]) {
      if (dist[child] - dist[i] != w) continue;
      g[i].push_back(child); indegree[child]++;
    }
  }
  stack<int> st; vector<int> toposort;
  for (int i = 1; i <= n; i++) {
    if (indegree[i] == 0) st.push(i);
  }
  while (st.size()) {
    auto node = st.top(); st.pop();
    toposort.push_back(node);
    for (auto child : g[node]) {
      if (--indegree[child] == 0) st.push(child);
    }
  }

  for (int i = 1; i <= n; i++) dp[i] = 0;
  dp[1] = 1LL;
  for (auto node : toposort) {
    for (auto child : g[node]) (dp[child] += dp[node]) %= MOD;
  }
  cout << dp[n] << " ";
  for (int i = 1; i <= n; i++) dp[i] = INF;
  dp[1] = 0;
  for (auto node : toposort) {
    for (auto child : g[node]) if (child != 1) dp[child] = min(dp[child], dp[node] + 1);
  }
  cout << dp[n] << " ";
  for (int i = 1; i <= n; i++) dp[i] = -1;
  dp[1] = 0;
  for (auto node : toposort) {
    for (auto child : g[node]) if (child != 1) dp[child] = max(dp[child], dp[node] + 1);
  }
  cout << dp[n] << " ";
  cout << endl;
}
