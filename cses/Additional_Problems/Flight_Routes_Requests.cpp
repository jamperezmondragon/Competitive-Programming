#pragma GCC optimize("unroll-loops", "O3")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
const int Mxn = 1e5 + 1;

struct DSU {
  vector<int> leader, Sz;
  DSU(int n) {leader.resize(n + 1), Sz.assign(n + 1, 1), iota(leader.begin(), leader.end(), 0);}
  int find(int x) {return ((leader[x] == x) ? x : (leader[x] = find(leader[x])));}
  void unite(int a, int b) {
    int A = find(a), B = find(b);
    if (A == B) return;
    if (Sz[A] < Sz[B]) swap(A, B);
    Sz[A] += Sz[B]; leader[B] = A;
  }
};

vector<int> g[Mxn], g_t[Mxn], Components[Mxn]; 
bool vis[Mxn];
int SCC[Mxn];
int ans = 0, n, m, x, y;
vector<int> eu;

void dfs_eu(int node) {
  vis[node] = 1;
  for (auto child : g[node]) {
    if (!vis[child]) dfs_eu(child);
  }
  eu.push_back(node);
}

void dfs(int node, int cnt) {
  SCC[node] = cnt;
  for (auto child : g_t[node]) {
    if (SCC[child] == 0) dfs(child, cnt);
  }
}


int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n >> m;
  DSU dsu(n);
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    g[x].push_back(y);
    g_t[y].push_back(x);
    dsu.unite(x, y);
  }
  for (int i = 1; i <= n; i++) {
    Components[dsu.find(i)].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    if (!Components[i].size()) continue;
    for (auto e : Components[i]) {
      if (!vis[e]) dfs_eu(e);
    }
    reverse(eu.begin(), eu.end());
    x = 0;
    for (auto e : eu) {
      if (!SCC[e]) dfs(e, ++x);
    }
    ans += dsu.Sz[i];
    if (x == dsu.Sz[i]) ans--;
    eu.clear();
  }
  cout << ans << '\n';
}
