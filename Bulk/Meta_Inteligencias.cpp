#pragma GCC optimize("unroll-loops","O3")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
const int Mxn = 1e5 + 1;

struct DSU {
  vector<int> leader, sz;
  stack<pair<int, int>> St;
  int cnt = 0;
  DSU(int N) {cnt = N; sz.assign(N + 1, 1); leader.resize(N + 1), iota(leader.begin(), leader.end(), 0);}
  int find(int x) {return ((x == leader[x]) ? x : find(leader[x]));}
  int unite(int u, int v) {
    u = find(u), v = find(v);
    if (u == v) return 0;
    if (sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v]; leader[v] = u;
    cnt--; St.emplace(u, v);
    return 1;
  }
  void undo() {
    auto [u, v] = St.top(); St.pop();
    sz[u] -= sz[v]; leader[v] = v;
    cnt++;
  }
} dsu(Mxn); 
vector<int> g[Mxn];
pair<int, int> edge[Mxn];
int Ans[Mxn];
int sz[Mxn];
int N, L;

int get_sz(int node = 1, int parent = 0) {
  sz[node] = 1;
  if (parent == g[node][0]) swap(g[node][0], g[node].back());
  for (auto &child : g[node]) {
    if (child == parent) continue;
    sz[node] += get_sz(child, node);
    if (sz[child] > sz[g[node][0]]) swap(child, g[node][0]);
  }
  return sz[node];
}

int dfs(int node = 1, int parent = 1) {
  for (int i = 1; i < size(g[node]); i++) {
    int child = g[node][i];
    if (child == parent) continue;
    int aux = dfs(child, node);
    while (aux--) dsu.undo();
  }

  int v = 0;
  if (g[node][0] != parent) v = dfs(g[node][0], node);

  for (int i = 1; i < size(g[node]); i++) {
    int child = g[node][i];
    if (child == parent) continue;
    v += dfs(child, node);
  }

  auto [x, y] = edge[node];
  v += dsu.unite(x, y);
  if (Ans[node] == -1) Ans[node] = dsu.cnt - 1;
  return v;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> N >> L;
  for (int i = 1; i <= N; i++) {
    Ans[i] = -1;
    int x; cin >> x;
    if (x == 0) continue;
    g[x].emplace_back(i);
    g[i].emplace_back(x);
  }
  get_sz();
  DSU ds(L);
  swap(dsu, ds);
  for (int i = 1; i <= N; i++) {
    auto &[x, y] = edge[i];
    cin >> x >> y;
  }
  dfs();
  for (int i = 1; i <= N; i++) {
    cout << Ans[i] << " ";
  }
}






















