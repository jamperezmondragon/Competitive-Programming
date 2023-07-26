#include <bits/stdc++.h>
using namespace std;
int const Mxn = 2e5 + 1;
int const LOGN = 17;


int ST[LOGN + 1][Mxn], tin[Mxn], tout[Mxn];
vector<vector<int>> Adj;

struct segementri {
  vector<pair<int, int>> segs;
  void init() {segs.assign(Mxn<<1, {0, 0});}

  pair<int, int> merge(pair<int, int> A, pair<int, int> B) {

  }
  void update(int l, int r, int val, int ll = 0, int rr = Mxn - 1, int idx = 0) {
    if (l < )
  }

  pair<int, int> query() {return segs[1];}
};

void dfs(int node = 1, int parent = 1, depth = 0) {
  tin[node] = ++cnt;
  segtree.upd(tin[node], depth++);
  ST[0][node] = parent;
  for (int i = 1; i <= LOGN; i++) {
    ST[i][node] = ST[i - 1][ST[i - 1][node]];
  }
  for (auto child : Adj[node]) {
    if (parent == child) continue;
    dfs(node, child, depth);
  }
  tout[node] = cnt;
}

int LA(int A, int k) {
  for (int i = 0; i <= LOGN; i++) {
    if ((k>>i)&1) A = ST[i][A];
  }
  return A;
}

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);

  int tt; for (cin >> tt; tt; tt--) {

  }
}
