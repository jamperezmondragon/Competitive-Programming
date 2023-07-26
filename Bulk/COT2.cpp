#include <bits/stdc++.h>
using namespace std;
int const Mxn = 4e4 + 1;
int const mxn = 1e5;
int const LOGN = 16;
vector<int> g[Mxn];
int A[Mxn];
int const K = 290;

// lca
int ST[LOGN + 1][Mxn];
int tin[Mxn], tout[Mxn], depth[Mxn];
vector<int> V;
void dfs(int node = 1, int parent = 1) {
  depth[node] = depth[parent] + 1;
  ST[0][node] = parent;
  for (int i = 1; i <= LOGN; i++) {
    ST[i][node] = ST[i - 1][ST[i - 1][node]];
  }
  tin[node] = V.size();
  V.push_back(node);
  for (auto child : g[node]) {
    if (child == parent) continue;
    dfs(child, node);
  }
  tout[node] = V.size();
  V.push_back(node);
}
int LA(int x, int k) {
  for (int i = 0; i <= LOGN; i++) {
    if ((k>>i)&1) x = ST[i][x];
  }
  return x;
}
int LCA(int x, int y) {
  if (depth[x] < depth[y]) swap(x, y);
  x = LA(x, depth[x] - depth[y]);
  if (x == y) return x; 
  for (int i = LOGN; i >= 0; i--) {
    if (ST[i][x] == ST[i][y]) continue;
    x = ST[i][x]; y = ST[i][y];
  }
  return ST[0][x];
}

//mo on trees
struct cesar {
  int a, b, lca, idx;
  bool f;
  bool operator<(const cesar & X) {return ((a/K == X.a/K) ? b < X.b : a < X.a);}
};
vector<cesar> Q;
int C[Mxn];
bool vis[2*Mxn];
int Ans[mxn];
int ans = 0, l = 0, r = 0;
void add(int x) {
  if (vis[x]) {
    C[A[x]]--; vis[x] = false; 
    if (C[A[x]] == 0) ans--;
  } else {
    C[A[x]]++; vis[x] = true; 
    if (C[A[x]] == 1) ans++;
  }
}
void momo() {
  sort(Q.begin(), Q.end());
  add(V[0]);
  for (auto [a, b, lca, idx, f] : Q) {
    while (r < b) add(V[++r]);
    while (r > b) add(V[r--]);
    while (l < a) add(V[l++]);
    while (l > a) add(V[--l]);
    if (f) add(lca);
    Ans[idx] = ans;
    if (f) add(lca);
  }
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q, cnt = 0; cin >> n >> q;
  map<int, int> cc;
  for (int i = 1; i <= n; i++) {
    cin >> A[i]; cc[A[i]] = 0;
  }
  for (auto &[x, y] : cc) y = cnt++;
  for (int i = 1; i <= n; i++) A[i] = cc[A[i]];
  for (int i = 1; i < n; i++) {
    int x, y; cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs();
  Q.resize(q);
  for (int i = 0; i < q; i++) {
    cin >> Q[i].a >> Q[i].b;
    if (tin[Q[i].a] > tin[Q[i].b]) swap(Q[i].a, Q[i].b);
    Q[i].idx = i; Q[i].lca = LCA(Q[i].a, Q[i].b); Q[i].f = true;
    if (Q[i].a == Q[i].lca) {
      Q[i].a = tin[Q[i].a], Q[i].b = tin[Q[i].b];
      Q[i].f = false;
    } else Q[i].a = tout[Q[i].a], Q[i].b = tin[Q[i].b];
  }
  momo();
  for (int i = 0; i < q; i++) {
    cout << Ans[i] << '\n';
  }
}
