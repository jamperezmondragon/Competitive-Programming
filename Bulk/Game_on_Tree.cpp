#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vii = vector<vi>;

vii g;
vi nim;

void dfs(int node = 1, int parent = 1) {
  for (auto child : g[node]) {
    if (child == parent) continue;
    dfs(child, node);
    nim[node] ^= nim[child] + 1;
  }
}

int main() {
  int n; cin >> n;
  g.assign(n + 1, {});
  nim.resize(n + 1);
  for (int i = 1; i < n; i++) {
    int x, y; cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs();
  cout << ((nim[1] == 0) ? "Bob\n" : "Alice\n");
}
