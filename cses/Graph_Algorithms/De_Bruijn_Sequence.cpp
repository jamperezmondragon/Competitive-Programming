#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)a.size()
const int Mxn = 1<<15;

set<int> g[Mxn];
vector<int> path;

void dfs(int node) {
  while (sz(g[node])) {
    auto it = g[node].begin();
    int child = *it;
    g[node].erase(it);
    dfs(child);
  }
  path.push_back(node);
}

int main() {
  int n; cin >> n; n--;
  if (n == 0) {
    cout << "10"; return 0;
  }
  for (int i = 0; i < (1<<n); i++) {
    int j = (i<<1)%(1<<n);
    g[i].insert(j);
    g[i].insert(j + 1);
  }
  dfs(0);
  reverse(path.begin(), path.end());
  for (int i = 0;  i < n - 1; i++) cout << 0;
  for (auto e : path) cout << (e&1);
}
