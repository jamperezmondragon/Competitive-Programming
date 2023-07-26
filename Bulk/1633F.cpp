#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int Mxn = 2e5 + 1;
#define DBG(x) if (dbg) cout << x << endl
bool dbg = true;

struct Tnode {
  int l, r, lz; ll sum, cnt;
  Tnode * ch[2];
  void merge() {sum = ch[0]->sum + ch[1]->sum; cnt = ch[0]->cnt + ch[1]->cnt;}
  void propagate() {
    if (!lz) return;
    ch[0]->sum *= -1; ch[1]->sum *= -1; ch[0]->cnt *= -1; ch[1]->cnt *= -1; lz ^= 1;
  }
  Tnode(int L, int R) {
    l = L, r = R, cnt = 0, sum = 0, lz = 0;
    if (L == R) return;
    int Mid = (L + R)>>1;
    ch[0] = new Tnode(L, Mid); ch[1] = new Tnode(Mid + 1, R);
    merge();
  }
  void upd(int L, int R) {
    if (r < L || R < l) return;
    if (L <= l && r <= R) {
      sum *= -1; cnt *= -1; lz ^= 1; return;
    }
    propagate();
    ch[0]->upd(L, R); ch[1]->upd(L, R);
    merge();
  }
  void point_upd(int x, ll y) {
    if (x < l || r < x) return;
    if (l == x && x == r) {
      sum = y; cnt = 1; return;
    }
    propagate();
    ch[0]->point_upd(x, y); ch[1]->point_upd(x, y);
    merge();
  }
};

vector<vector<pair<int, ll>>> g;
vector<vector<int>> adj;

struct HLD {
  vector<int> sz, head, depth, tin, P, A;
  Tnode SegTree;
  int cnt;
  vector<vector<int>> adj;

  int get_sz(int node = 1, int parent = 0) {
    if (parent == adj[node][0]) swap(adj[node][0], adj[node].back());
    sz[node] = 1;
    for (auto &child : adj[node]) {
      if (child == parent) continue;
      sz[node] += get_sz(child, node);
      if (sz[child] > sz[adj[node][0]]) swap(child, adj[node][0]);
    }
    return sz[node];
  }
  
  void dfs(int node = 1, int parent = 1) {
    depth[node] = depth[parent] + 1;
    P[node] = parent;
    tin[node] = cnt++;
    for (auto child : adj[node]) {
      if (child == parent) continue;
      head[child] = ((child == adj[node][0]) ? head[node] : child);
      dfs(child, node);
    }
  }

  HLD(int n, vector<vector<int>> & V, vector<int> & A_) {
    SegTree = Tnode(0, n + 1); A = A_;
    sz.resize(n + 1), head.resize(n + 1), depth.resize(n + 1), tin.resize(n + 1), P.resize(n + 1);
    cnt = 0; adj = V; get_sz(); head[1] = 1; dfs(); SegTree.point_upd(tin[1], 0);
  }

  void upd(int u, int v = 1) {
    SegTree.point_upd(tin[u], A[u]);
    for (u = P[u]; head[u] != head[v]; u = P[head[u]]) {
      if (depth[head[u]] < depth[head[v]]) swap(u, v);
      SegTree.upd(tin[head[u]], tin[u]);
    }
    if (tin[u] < tin[v]) swap(u, v);
    SegTree.upd(tin[v], tin[u]);
  }

  array<ll, 2> query() {return {SegTree.sum, SegTree.cnt};}
};

int dfs(int node = 1, int parent = 0) {
  sz[node] = V[node];
  for (auto [child, w] : g[node]) {
    if (child == parent) continue;
    A[child] = w;
    sz[node] += dfs(child, node);
  }
  if (sz[node]&1) matching.push_back(A[node]);
  return sz[node];
}

ll C = 0;

ll V[Mxn], sz[Mxn];
vector<ll> matching;

namespace checker {
}

 


int main() {
  int n, x, y; cin >> n; g.resize(n + 1); adj.resize(n + 1);
  for (int i = 1; i < n; i++) {
    V[i + 1] = 0;
    cin >> x >> y;
    g[x].emplace_back(y, (ll)i);
    g[y].emplace_back(x, (ll)i);
    adj[x].emplace_back(y);
    adj[y].emplace_back(x);
  }
  dfs();
  V[1] = 1;
  matching.clear();
  hld::init();
  while (cin >> x) {
    if (x == 3) break;
    if (x == 1) {
      cin >> y;
      V[y] = 1;
      C += A[y];
      hld::upd(y);
      auto X = query();
      if (X[1] == 0) cout << (C + X[0])/2 << endl;
      else cout << 0 << endl;
    } else {
      auto X = query();
      if (X[1] != 0) cout << 0 << endl;
      else {
        dfs();
        cout << size(matching) << " ";
        sort(matching.begin(), matching.end());
        for (auto e : matching) cout << e << " ";
        cout << endl;
        matching.clear();
      }
    }
  }
}

