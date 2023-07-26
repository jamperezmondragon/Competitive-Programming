#include <bits/stdc++.h>
using namespace std;
int const Mxn = 1<<18;
int const LOGN = 18;  

vector<vector<pair<int , int>>> Adj;

struct DSU {
  int Sz[Mxn], Leader[Mxn];
  void make_set(int v)  {
    Sz[v] = 1, Leader[v] = v;
  }
  void init(int n) {
    for (int i = 1; i <= n; i++) make_set(i);
  }
  int find_set(int v) {
    if (Leader[v] == v) return v;
    return find_set(Leader[v]);
  }
  void unite(int a, int b, int w) {
    int A = find_set(a), B = find_set(b);
    if (A == B) return;
    if (Sz[A] < Sz[B]) swap(A, B);
    Leader[B] = A; Sz[A] += Sz[B];
    Adj[a].push_back({b, w});
    Adj[b].push_back({a, w});
  }
} dsu;

struct lca {
  int Depth[Mxn], ST[LOGN + 1][Mxn], ST_max[LOGN + 1][Mxn];
  void dfs(int node, int parent, int W) {
    Depth[node] = Depth[parent] + 1;
    ST[0][node] = parent; ST_max[0][node] = W;
    for (int i = 1; i <= LOGN; i++) {
      ST[i][node] = ST[i - 1][ST[i - 1][node]];
      ST_max[i][node] = max(ST_max[i - 1][node], ST_max[i - 1][ST[i - 1][node]]);
    }
    for (auto [child, w]: Adj[node]) {
      if (parent == child) continue;
      dfs(child, node, w);
    }
  }
  void init() { Depth[1] = -1; dfs(1, 1, 0);}
  pair<int, int> LCA(int A, int B, int ans = 0) {
    if (Depth[A] < Depth[B]) swap(A, B);
    int jump = Depth[A] - Depth[B];
    for (int i = LOGN; i >= 0; i--) {
      if (jump&(1<<i)) {
        ans = max(ans, ST_max[i][A]); A = ST[i][A];
      }
    }
    if (A == B) return {A, ans};
    for (int i = LOGN; i >= 0; i--) {
      if (ST[i][A] != ST[i][B]) {
        ans = max({ans, ST_max[i][A], ST_max[i][B]});
        A = ST[i][A], B = ST[i][B];
      }
    }
    return {ST[0][A], ans};
  }
} cerrao;

struct segementri {
  vector<pair<int, int>> segs; 
  pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
    if (a.first == 0) return b;
    if (b.first == 0) return a;
    return cerrao.LCA(a.first, b.first, max(a.second, b.second));
  }
  void init(int n) {
    segs.assign(2*Mxn, {0, 0});
    for (int i = Mxn + 1; i <= Mxn + n; i++) segs[i].first = i - Mxn;
    for (int i = Mxn - 1; i > 0; i--) {
      segs[i] = merge(segs[2*i], segs[2*i + 1]);
    }
  }
  int query(int l, int r) {
    pair<int, int> ans = {0, 0};
    for (l += Mxn, r += Mxn + 1; l < r; l /= 2, r /= 2) {
      if (l&1) ans = merge(segs[l++], ans);
      if (r&1) ans = merge(segs[--r], ans);
    }
    return ans.second;
  }
} segtree;

int main() {
  int tt;
  for (cin >> tt; tt; tt--) {
    int n, m, q; cin >> n >> m >> q;
    Adj.clear(); Adj.resize(n + 1); dsu.init(n);
    for (int i = 1, x, y; i <= m; i++) {
      cin >> x >> y; dsu.unite(x, y, i);
    }
    cerrao.init(); segtree.init(n);
    while (q--) {
      int l, r; cin >> l >> r;
      cout << segtree.query(l, r) << " ";
    }
    cout << endl;
  }
}
