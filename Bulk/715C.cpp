#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int Mxn = 1e5 + 1;

vector<vector<pair<int, int>>> Adj;
map<int, ll> V;
ll M, ans = 0;
int n;

//centroid decomp
bool used[Mxn];
int Sz[Mxn];

int dfs_sz(int node, int parent = -1) {
  Sz[node] = 1;
  for (auto [child, w] : Adj[node]) {
    if (child == parent || used[child]) continue;
    Sz[node] += dfs_sz(child, node);
  }
  return Sz[node];
}
int get_centroid(int node, int S, int parent = -1) {
  for (auto [child, w] : Adj[node]) {
    if (child == parent || used[child]) continue;
    if (2*Sz[child] > S) return get_centroid(child, S, node);
  }
  return node;
}

void centroid_decomp(int node) {
  int c = get_centroid(node, dfs_sz(node));
  used[c] = true;

  for (auto [child, w] : Adj[c]) {
    if (!used[child]) dfs(child, w, 0);
  }

  for (auto [child, w] : Adj[c]) {
    if (!used[child]) centroid_decomp(child);
  }
}

int main() {
  cin >> n >> M; Adj.assign(n, {});
  for (int i = 1; i < n; i++) {
    int x, y, w; cin >> x >> y >> w;
    Adj[x].push_back({y, w});
    Adj[y].push_back({x, w});
  }


}
