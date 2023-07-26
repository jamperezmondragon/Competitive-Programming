#include <bits/stdc++.h>
using namespace std;
int const Mxn = 1<<18;
int n, q, x, y, z;

struct segementri {
  vector<int> segs;
  void init() {segs.assign(Mxn<<1, 0);}
  void upd(int i, int val) {
    segs[i += Mxn] = val;
    for (i /= 2; i > 0; i /= 2) segs[i] = max(segs[2*i], segs[2*i + 1]);
  }
  int query(int l, int r, int val = 0) {
    for (l += Mxn, r += Mxn + 1; l < r; l /= 2, r /= 2) {
      if (l&1) val = max(val, segs[l++]);
      if (r&1) val = max(val, segs[--r]);
    }
    return val;
  }
} segtree;

vector<vector<int>> Adj(Mxn);
int Sz[Mxn], head[Mxn], preorder[Mxn];
int reversepre[Mxn], postorder[Mxn];
int Depth[Mxn], Val[Mxn], Parent[Mxn];
int cnt = 0;
//hld decomp
void dfs_Sz(int node, int parent) {
  Parent[node] = parent; Sz[node] = 1;
  Depth[node] = Depth[parent] + 1;
  if (parent == Adj[node][0]) swap(Adj[node].back(), Adj[node][0]);
  for (auto &child : Adj[node]) {
    if (child == parent) continue;
    dfs_Sz(child, node); Sz[node] += Sz[child];
    if (Sz[child] > Sz[Adj[node][0]]) swap(child, Adj[node][0]);
  }
}
void dfs_hld(int node, int parent) {
  reversepre[cnt] = node;
  preorder[node] = cnt++;
  for (auto child : Adj[node]) {
    if (child == parent) continue;
    head[child] = ((child == Adj[node][0]) ? head[node] : child);
    dfs_hld(child, node);
  }
  segtree.upd(preorder[node], Val[node]);
  postorder[node] = cnt - 1;
}
void hld_init() {
  segtree.init(); head[1] = 1; dfs_Sz(1, 1); dfs_hld(1, 1);
}
//Queries
int LCA(int a, int b) { //lca - funciona yay
  for (; head[a] != head[b]; a = parent[head[a]]) {
    if (depth[head[a]] < depth[head[b]]) swap(a, b);
  }
  return (depth[a] < depth[b] ? a : b);
}
int LA(int A, int k) { //level ansestor.
  if (Depth[A] < k) return -1;
  while (Depth[A] - Depth[head[A]] < k) {
    k -= Depth[A] - Depth[head[A]] + 1;
    A = Parent[head[A]];
  }
  return reversepre[preorder[A] - k];
}
int Path_Query(int A, int B, int ans = 0) { //Path queries - funciona yay
  for (; head[A] != head[B]; A = Parent[head[A]]) {
    if (Depth[head[A]] < Depth[head[B]]) swap(A, B);
    ans = max(segtree.query(preorder[head[A]], preorder[A]), ans);
  }
  if (Depth[A] < Depth[B]) swap(A, B);
  return max(segtree.query(preorder[B], preorder[A]), ans);
}
int Subtree_Query(int A) { //Subtree queries
  return segtree.query(preorder[A], postorder[A]);
}

int main() {
  cin.tie(0), ios_base::sync_with_stdio(false);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> Val[i];
  }
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    Adj[x].push_back(y);
    Adj[y].push_back(x);
  }
  hld_init();
  while (q--) {
    cin >> x >> y >> z;
    if (x - 1) {
      cout << LA(y, z) << " ";
    } else {
      segtree.upd(preorder[y], z);
    }
  }
}
