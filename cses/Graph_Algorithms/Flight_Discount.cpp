#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int Mxn = 1e5 + 1;
const ll INF = 1e17;


vector<pair<int , ll>> Adj[Mxn];
ll dist[2][Mxn];

struct dijkstra_obj {
  int node, state; ll w;
  bool operator<(const dijkstra_obj & A) const {return w > A.w;};
};

void dijkstra(int src = 1) {
  for (int i = 0; i < Mxn; i++) dist[0][i] = dist[1][i] = INF;
  dist[0][src] = dist[1][src] = 0;
  priority_queue<dijkstra_obj> pq;
  pq.push({src, 0, 0});

  while (pq.size()) {
    auto [node, state, W] = pq.top(); pq.pop();
    if (dist[state][node] != W) continue;

    for (auto [child, w] : Adj[node]) {
      if (dist[state][child] > dist[state][node] + w) {
        dist[state][child] = dist[state][node] + w;
        pq.push({child, state, dist[state][child]});
      }

      if (state == 0 && dist[1][child] > dist[0][node] + w/2)  {
        dist[1][child] = dist[0][node] + w/2;
        pq.push({child, 1, dist[1][child]});
      }
    }

  }

}


int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b; ll c; cin >> a >> b >> c;
    Adj[a].push_back({b, c});
  }
  dijkstra();
  cout << min(dist[1][n], dist[0][n]) << '\n';
}
