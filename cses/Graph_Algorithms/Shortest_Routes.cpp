#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int Mxn = 1e5 + 1;
const ll INF = 1e17;

vector<pair<int, ll>> Adj[Mxn];

ll dist[Mxn];

struct dijkstra_obj {
  int node; ll w; 
  bool operator<(const dijkstra_obj & A) const {return w > A.w;}
};
void dijkstra(int src) {
  for (int i = 1; i < Mxn; i++) dist[i] = INF;
  dist[src] = 0;
  priority_queue<dijkstra_obj> pq; pq.push({src, 0});
  while (pq.size()) {
    auto [node, W] = pq.top(); pq.pop();
    if (dist[node] != W) continue;
    for (auto  [child, w] : Adj[node]) {
      if (dist[node] + w < dist[child]) {
        pq.push({child, dist[child] = dist[node] + w});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y; ll w; cin >> x >> y >> w;
    Adj[x].push_back({y, w});
  }
  dijkstra(1);
  for (int i = 1; i <= n; i++) {
    cout << dist[i] << " ";
  }
}
