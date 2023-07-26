#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int Mxn = 1e5 + 1;

vector<pair<int, ll>> Adj[Mxn];

struct dijkstra_obj {
  int a; ll w; 
  bool operator<(const dijkstra_obj & A) const {return w > A.w;}
};

int main() {
  int n, m, k; cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    int x, y, w; cin >> x >> y >> w;
    Adj[x].push_back({y, w});
  }
  priority_queue<dijkstra_obj> pq;
  vector<int> vis(n + 1, 0); pq.push({1, 0}); 

  while (pq.size() && vis[n] <= k) {
    auto [node, W] = pq.top(); pq.pop();
    vis[node]++;
    if (vis[node] > k) continue;
    if (node == n) cout << W << " ";
    for (auto [child, w] : Adj[node]) {
      pq.push({child, W + w});
    }
  }
}



