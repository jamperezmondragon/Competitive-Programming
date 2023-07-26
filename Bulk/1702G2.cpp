#include <bits/stdc++.h>
using namespace std;
int const Mxn = 2e5 + 10;
int const LOGN = 19;
int n, k, q, x, y, cnt = 0; 
int Preorder[Mxn], Postorder[Mxn], Depth[Mxn];
int ST[LOGN + 1][Mxn];
vector<int> Adj[Mxn];
 
void dfs(int node, int parent) {
  Depth[node] = Depth[parent] + 1;
  ST[0][node] = parent;
  for (int i = 1; i <= LOGN; i++) ST[i][node] = ST[i - 1][ST[i - 1][node]];
 
  Preorder[node] = ++cnt;
  for (auto child : Adj[node]) {
    if (child == parent) continue;
    dfs(child, node);
  }
  Postorder[node] = ++cnt;
}
 
int LA(int A, int step) {
  for (int i = LOGN; i >= 0; i--) {
    if ((step>>i)&1) A = ST[i][A];
  }
  return A;
}
 
int LCA(int A, int B) {
  if (Depth[A] < Depth[B]) swap(A, B);
  A = LA(A, Depth[A] - Depth[B]);
  if (A == B) return A;
  for (int i = LOGN; i >= 0; i--) {
    if (ST[i][A] != ST[i][B]) A = ST[i][A], B = ST[i][B];
  }
  return ST[0][A];
}
bool is_ansestor(int A, int B) {
  return (Preorder[A] <= Preorder[B] && Postorder[B] <= Postorder[A]);
}
 
void query() {
  bool flag = true; int seg = -1;
  cin >> k; vector<int> v(k);
  for (auto &e : v) cin >> e;
  sort(v.begin(), v.end(),
      [](int a, int b) {return Depth[a] > Depth[b]; }
  );
 
  int lca = v[0];
  for (auto e : v) {
    lca = LCA(e, lca);
    if (is_ansestor(e, v[0])) continue;
    if (seg == -1) seg = e;
    else if (!is_ansestor(e, seg)) flag = false;
  }
  if (seg != -1 && LCA(v[0], seg) != lca) flag = false;
 
  cout << (flag ? "YES" : "NO") << endl;
}
 
int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    Adj[x].push_back(y);
    Adj[y].push_back(x);
  }
  Depth[1] = 0;
  dfs(1, 1);
  for (cin >> q; q; q--) {
    query();
  }
}
