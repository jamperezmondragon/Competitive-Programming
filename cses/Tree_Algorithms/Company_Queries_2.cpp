#include <bits/stdc++.h>
using namespace std;
const int Mxn = 2e5 + 1; 
const int LOGN = 18;

int centroid[LOGN][Mxn], LCA[LOGN][Mxn], P[Mxn], sz[Mxn];
vector<int> g[Mxn];
bool used[Mxn];

int get_sz(int node, int parent) {
  sz[node] = 1;
  for (auto child : g[node]) {
    if (child == parent || used[child]) continue;
    sz[node] += get_sz(child, node);
  }
  return sz[node];
}
int get_centroid(int node, int parent, int S) {
  for (auto child : g[node]) {
    if (child == parent || used[child]) continue;
    if (2*sz[child] > S) return get_centroid(child, node, S);
  }
  return node;
}
void dfs(int node, int parent, int lvl, int c, int lca) {
  centroid[lvl][node] = c; LCA[lvl][node] = lca;
  for (auto child : g[node]) {
    if (child == parent || used[child]) continue;
    if (child == P[node] && lca == node) dfs(child, node, lvl, c, child);
    else dfs(child, node, lvl, c, lca);
  }
}
void centroid_decomp(int node = 1, int lvl = 0)  {
  int c = get_centroid(node, node, get_sz(node, node));
  dfs(c, c, lvl, c, c);
  used[c] = true;
  for (auto child : g[c]) {
    if (!used[child]) centroid_decomp(child, lvl + 1);
  }
}

int Lca(int u, int v, int cnt = 0, int ans = 0) {
  if (u == v) return u;
  while (centroid[cnt + 1][u] == centroid[cnt + 1][v]) cnt++;
  ans = centroid[cnt][u];
  if (LCA[cnt][u] != centroid[cnt][u]) ans = LCA[cnt][u];
  if (LCA[cnt][v] != centroid[cnt][v]) ans = LCA[cnt][v];
  return ans;
}

int main() {
  int n, q; cin >> n >> q;
  for (int i = 2; i <= n; i++) {
    cin >> P[i]; 
    g[P[i]].push_back(i);
    g[i].push_back(P[i]);
  }
  centroid_decomp();
  while (q--) {
    int x, y; cin >> x >> y;
    cout << Lca(x, y) << endl;
  }
}
