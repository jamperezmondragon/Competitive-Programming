#include <bits/stdc++.h>
#pragma GCC optimize("unroll-loops", "O3")
#pragma GCC target("avx2")

using namespace std;
const int Mxn = 2e5 + 1;
const int LOGN = 17;

//dsu
vector<pair<int, int>> g[Mxn];
vector<array<int, 3>> Vec;

vector<int> sz, leader;
void init(int n) {sz.assign(n + 1, 1), leader.resize(n + 1), iota(leader.begin(), leader.end(), 0);}
int find(int x) {return ((leader[x] == x) ? x : (leader[x] = find(leader[x])));}
void unite(int u, int v, int W) {
  int U = find(u), V = find(v);
  if (U == V) return;
  g[u].emplace_back(v, W);
  g[v].emplace_back(u, W);
  if (sz[U] < sz[V]) swap(U, V);
  sz[U] += sz[V]; leader[V] = U;
}

//bin lifting en el MST
int ST[LOGN + 1][Mxn], dp[LOGN + 1][Mxn], depth[Mxn];

void dfs(int node = 1, int parent = 1, int W = 0) {
  ST[0][node] = parent; dp[0][node] = W;
  depth[node] = depth[parent] + 1;
  for (int i = 1; i <= LOGN; i++) {
    ST[i][node] = ST[i - 1][ST[i - 1][node]];
    dp[i][node] = max(dp[i - 1][node], dp[i - 1][ST[i - 1][node]]);
  }
  for (auto [child, w] : g[node]) {
    if (child == parent) continue;
    dfs(child, node, w);
  }
}

pair<int, int> jump(int node, int k, int ans = 0) {
  for (int i = 0; i <= LOGN; i++) {
    if ((k>>i)&1) {
      ans = max(ans, dp[i][node]);
      node = ST[i][node];
    }
  }
  return {node, ans};
}

int query(int A, int B, int ans = 0) {
  if (depth[A] < depth[B]) swap(A, B);
  tie(A, ans) = jump(A, depth[A] - depth[B]);
  if (A == B) return ans;
  for (int i = LOGN; i >= 0; i--) {
    if (ST[i][A] == ST[i][B]) continue;
    ans = max({ans, dp[i][A], dp[i][B]});
    A = ST[i][A]; B = ST[i][B];
  }
  return max({ans, dp[0][A], dp[0][B]});
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, m, q, x, y, w; cin >> n >> m >> q;
  for (int i = 0; i < m; i++) {
    cin >> x >> y >> w;
    Vec.push_back({w, y, x});
  }
  sort(Vec.begin(), Vec.end());
  init(n);
  for (auto [c, b, a] : Vec) unite(a, b, c);
  depth[1] = 0;
  dfs();
  while (q--) {
    cin >> x >> y >> w;
    cout << ((w >= query(x, y)) ? 1 : 0) << endl;
  }
}

