#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, max_set = 1;

map<pair<int, int>, vector<pair<int, int>>> Somewhat_bullshit_Edges;

stack<pair<int, int>> ROLLBACK;
vector<int> Leader, Sz, val;
void make_set(int v) {
  Leader[v] = v; Sz[v] = 1;
}
int find_set(int v) {
  if (Leader[v] == v) return v;
  return find_set(Leader[v]);
}
int unite_sets(int v, int u) {
  int V = find_set(v), U = find_set(u);
  if (V == U) return 0;
  if (Sz[V] < Sz[U]) swap(V, U);
  Leader[U] = V; Sz[V] += Sz[U];
  max_set = max(max_set, Sz[V]);
  ROLLBACK.push({U, V});
  return 1;
}
void rollback() {
  pair<int, int> aux = ROLLBACK.top(); 
  int U = aux.first, V = aux.second;
  Leader[U] = U; Sz[V] -= Sz[U];
  ROLLBACK.pop();
}


int main() {
  cin >> n >> m;
  cin.tie(0); ios_base::sync_with_stdio(false);
  Sz.resize(n + 1); val.resize(n + 1); Leader.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> val[i]; make_set(i);
  }
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    if (val[x] == val[y]) {
      unite_sets(x, y); continue;
    }
    if (val[x] < val[y]) swap(x, y);
    Somewhat_bullshit_Edges[{val[x], val[y]}].push_back({x, y});
  }
  for (auto [X, V] : Somewhat_bullshit_Edges) {
    int cnt = 0;
    for (auto &[a, b] : V) {
      cnt += unite_sets(a, b);
    }
    while (cnt--) rollback();
  }
  cout << max_set << endl;
}
