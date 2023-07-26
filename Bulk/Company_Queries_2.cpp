#include <bits/stdc++.h>
using namespace std;
int const Mxn = 2e5 + 1;
int const mxn = 4e5 + 5;
int const LOGN = 19;
vector<int> g[Mxn];
int ST[LOGN][mxn];
int depth[Mxn];
int tin[Mxn];
vector<int> euler;

void dfs(int node = 1, int parent = 1) {
  tin[node] = (int)euler.size();
  euler.push_back(node);
  depth[node] = depth[parent] + 1;
  for (auto child : g[node]) {
    if (child == parent) continue;
    dfs(child, node);
    euler.push_back(node);
  }
}
int comb(int x, int y) {return (depth[x] < depth[y]) ? x : y;}
void build() {
  int N = (int)euler.size();
  for (int i = 0; i < N; i++) ST[0][i] = euler[i];
  for (int i = 0; i < LOGN - 1; i++) {
    for (int j = 0; j + (1<<i) < N; j++) {
      ST[i + 1][j] = comb(ST[i][j], ST[i][j + (1<<i)]);
    }
  }
}
int query(int l, int r) {
  int i = 31 - __builtin_clz(r - l + 1);
  return comb(ST[i][l], ST[i][r - (1<<i) + 1]);
}
int LCA(int A, int B) {
  if (tin[A] > tin[B]) swap(A, B);
  return query(tin[A], tin[B]);
}

int main() {
  int n, q; cin >> n >> q;
  for (int i = 2; i <= n; i++) {
    int x; cin >> x; 
    g[x].push_back(i);
    g[i].push_back(x);
  }
  dfs(); build();
  for (int i = 0; i < q; i++) {
    int x, y; cin >> x >> y;
    cout << LCA(x, y) << '\n';
  }
}
