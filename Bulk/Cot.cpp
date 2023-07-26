#include <bits/stdc++.h>
using namespace std;
int const Mxn = 1<<19;
int const LOGN = 19;
int n, q, x, y, z;

// problem: https://www.spoj.com/problems/COT/

//bit n stuff
struct fenwi {
  int BIT[Mxn];
  void upd(int i, int val) {
    for (; i < Mxn; i += i&(-i)) BIT[i] += val;
  }
  int sum(int i, int res = 0)  {
    for (; i > 0; i -= i&(-i)) res += BIT[i];
    return res;
  }
 } bit;

//LCA n stuff
int preorder[Mxn], postorder[Mxn], Depth[Mxn];
int cost[Mxn];
int ST[LOGN + 1][Mxn];
vector<int> Adj[Mxn];
int pre_cnt = 0;

void dfs(int node, int parent) {
  Depth[node] = Depth[parent] + 1;
  ST[0][node] = parent;
  for (int i = 1; i <= LOGN; i++) ST[i][node] = ST[i - 1][ST[i - 1][node]];
  preorder[node] = ++pre_cnt;
  for (auto child : Adj[node]) {
    if (child == parent) continue;
    dfs(child, node);
  }
  postorder[node] = ++pre_cnt;
}
int LA(int node, int k) {
  for (int i = LOGN; i >= 0; i--) {
    if ((k>>i)&1) node = ST[i][node];
  }
  return node;
}
int LCA(int A, int B) {
  if (Depth[A] < Depth[B]) swap(A, B);
  A = LA(A, Depth[A] - Depth[B]);
  if (A == B) return A;
  for (int i = LOGN; i >= 0; i--) {
    if (ST[i][A] != ST[i][B]) {
      A = ST[i][A], B = ST[i][B];
    }
  }
  return ST[0][A];
}

//parallel binary search
struct Queries {
  int A, B, lca, kth, idx;
};
vector<Queries> Q;
vector<pair<int, int>> V;
int ans[Mxn];

bool check(Queries X, int cnt = 0) {
  if (X.lca == X.A || X.lca == X.B) {
    if (Depth[X.A] < Depth[X.B]) swap(X.A, X.B);
    cnt = bit.sum(preorder[X.A]) - bit.sum(preorder[X.B]);
    if (bit.sum(preorder[X.B]) - bit.sum(preorder[X.B] - 1) == 1) cnt++;
  } else {
    cnt += bit.sum(preorder[X.B]);
    cnt += bit.sum(preorder[X.A]);
    cnt -= 2*bit.sum(preorder[X.lca]);
    if (bit.sum(preorder[X.lca]) - bit.sum(preorder[X.lca] - 1) == 1) cnt++;
  }
  return cnt >= X.kth;
}

void parallel_binary_search(int l, int r, vector<Queries> candiperreo) {
  if (l + 1 == r) {
    for (auto X : candiperreo) ans[X.idx] = V[l].first;
    return;
  }
  int m = (l + r)>>1;
  vector<Queries> Left, Right;
  for (int i = l; i < m; i++) {
    bit.upd(preorder[V[i].second], 1);
    bit.upd(postorder[V[i].second], -1);
  }
  for (auto X : candiperreo) {
    if (check(X)) Left.push_back(X);
    else Right.push_back(X);
  }
  parallel_binary_search(m, r, Right); Right.clear();
  for (int i = l; i < m; i++) {
    bit.upd(preorder[V[i].second], -1);
    bit.upd(postorder[V[i].second], 1);
  }
  parallel_binary_search(l, m, Left); Left.clear();
}

int main() {
  cin.tie(0), ios_base::sync_with_stdio(false);
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> cost[i];
  }
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    Adj[x].push_back(y);
    Adj[y].push_back(x);
  }
  Depth[1] = -1;
  dfs(1, 1);
  Q.resize(q);
  for (int i = 1; i <= n; i++) {
    V.push_back({cost[i], i});
  }
  sort(V.begin(), V.end());
  for (int i = 0; i < q; i++) {
    cin >> Q[i].A >> Q[i].B >> Q[i].kth;
    Q[i].lca = LCA(Q[i].A, Q[i].B);
    Q[i].idx = i;
  }
  parallel_binary_search(0, n, Q);
  for (int i = 0; i < q; i++) {
    cout << ans[i] << "\n";
  }
}
