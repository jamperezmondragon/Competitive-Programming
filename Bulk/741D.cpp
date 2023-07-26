#include <bits/stdc++.h>
using namespace std;
const int Mxn = 5e5 + 1;

vector<int> g[Mxn];
int W[Mxn];
int sz[Mxn];
int Depth[Mxn];
int Ans[Mxn];
int tin[Mxn];
vector<int> euler;

int get_sz(int node = 1, int parent = 1) {
  W[node] ^= W[parent];
  Depth[node] = Depth[parent] + 1;
  sz[node] = 1;
  if (g[node][0] == parent) swap(g[node][0], g[node].back());
  for (auto &child : g[node]) {
    if (child == parent) continue;
    sz[node] += get_sz(child, node);
    if (sz[child] > sz[g[node][0]]) swap(child, g[node][0]);
  }
  return sz[node];
}

int cnt[1<<26];
stack<pair<int, int>> St;
void undo() {auto [x, y] = St.top(); St.pop(); cnt[x] = y;}
void add(int x, int y) {St.push({x, cnt[x]}); cnt[x] = max(y, cnt[x]);}


void dfs(int node = 1, int parent = 1, int root = 1, int aux = 0) {

  for (int i = 1; i < size(g[node]); i++) {
    auto child = g[node][i];
    if (child == parent) continue;
    dfs(child, node, child);
    Ans[node] = max(Ans[node], Ans[child]);
    aux = sz[child];
    while (aux--) undo();
  }

  if (g[node][0] != parent) dfs(g[node][0], node);
  Ans[node] = max(Ans[g[node][0]], Ans[node]);

  for (int i = 1; i < size(g[node]); i++) {
    int child = g[node][i];

    for (int j = tin[child]; j < tin[child] + sz[child]; j++) {
      int mask = W[euler[j]];
      Ans[node] = max(Ans[node], Depth[euler[j]] - 2*Depth[node] + cnt[mask]);
      for (int k = 0; k < 26; k++) {
        Ans[node] = max(Ans[node], Depth[euler[j]] - 2*Depth[node] + cnt[mask^(1<<k)]);
      }
    }

    for (int j = tin[child]; j < tin[child] + sz[child]; j++) {
      int mask = W[euler[j]];
      add(mask, Depth[euler[j]]);
    }

  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 2; i <= n; i++) {
    int x; char c; cin >> x >> c;
    W[i] = 1;
    W[i] <<= (c - 'a');
    g[x].push_back(i);
    g[i].push_back(x);
  }
  get_sz();
  dfs();
  for (int i = 1; i <= n; i++) {
    cout << Ans[i] << " ";
  }
}

