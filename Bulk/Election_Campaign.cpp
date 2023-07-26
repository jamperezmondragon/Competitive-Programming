#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int Mxn = 1e5 + 1;
const int mxn = 2e5 + 1;
const int LOGN = 17;


//binary lifting :clown:
int tin[Mxn], tout[Mxn], cnt = 1, ST[LOGN + 1][Mxn], depth[Mxn];
vector<int> g[Mxn];
void build(int node = 1, int parent = 1) {
  ST[0][node] = parent; depth[node] = depth[parent] + 1;
  for (int i = 1; i <= LOGN; i++) {
    ST[i][node] = ST[i - 1][ST[i - 1][node]];
  }
  tin[node] = cnt++; 
  for (auto child : g[node]) {
    if (child == parent) continue;
    build(child, node);
  }
  tout[node] = cnt++;
}
int jump(int A, int k) {
  for (int i = 0; i <= LOGN; i++) {
    if ((k>>i)&1) A = ST[i][A];
  }
  return A;
}
int LCA(int A, int B) {
  if (depth[A] < depth[B]) swap(A, B);
  A = jump(A, depth[A] - depth[B]);
  if (A == B) return A;
  for (int i = LOGN; i >= 0; i--) {
    if (ST[i][A] != ST[i][B]) A = ST[i][A], B = ST[i][B];
  }
  return ST[0][A];
}

//fenwi
struct fenwi {
  ll BIT[mxn];
  void upd(int i, ll val = 0) {
    for (; i < mxn; i += i&-i) BIT[i] += val;
  }
  ll sum(int i, ll val = 0) {
    for (; i > 0; i -= i&-i) val += BIT[i];
    return val;
  }
  ll query(int a, int b, int c) {
    return sum(tin[a]) + sum(tin[b]) - 2*sum(tin[c]);
  }

} bit[2];

//solve
struct query {int a, b, c;};
ll dp[Mxn], children_sum[Mxn];
vector<query> Q[Mxn];

void dfs(int node = 1, int parent = 1) {
  children_sum[node] = 0;
  for (auto child : g[node]) {
    if (child == parent) continue;
    dfs(child, node);
    children_sum[node] += dp[child];
  }
  dp[node] = children_sum[node];
  bit[0].upd(tin[node], children_sum[node]);
  bit[0].upd(tout[node], -children_sum[node]);
  for (auto [a, b, c] : Q[node]) {
    dp[node] = max(dp[node], bit[0].query(a, b, node) + children_sum[node] - bit[1].query(a, b, node) + c);
  }
  bit[1].upd(tin[node], dp[node]);
  bit[1].upd(tout[node],-dp[node]);
}


int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m; cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y; cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  cin >> m; build();
  for (int i = 0; i < m; i++) {
    int x, y, c; cin >> x >> y >> c;
    Q[LCA(x, y)].push_back({x, y, c});
  }
  dfs();
  cout << dp[1] << '\n';
}
