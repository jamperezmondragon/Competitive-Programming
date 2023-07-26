#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)a.size()

vector<vector<pair<int, int>>> Adj;
bool vis[200001];

int dfs(int node, int ans = 1)  {
  vis[node] = true; 
  for (auto [child, val] : Adj[node]) { 
    if (!vis[child] && val == 0) ans += dfs(child);
  }
  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int tt; for (cin >> tt; tt; tt--) {
    int n, m; cin >> n >> m;
    Adj.clear(); Adj.resize(n + 1);

    vector<vector<pair<int, int>>> Bits(31);

    for (int i = 0; i < m; i++) {
      int x, y, z; cin >> x >> y >> z;
      Adj[x].push_back({y, 0});
      Adj[y].push_back({x, 0});
      for (int j = 0; j < 31; j++) {
        if ((z>>j)&1) {
          Bits[j].push_back({x, sz(Adj[x]) - 1});
          Bits[j].push_back({y, sz(Adj[y]) - 1});
        }
      }
    }

    int ans = 0;
    for (int j = 30; j >= 0; j--) {
      if (!sz(Bits[j])) continue;
      for (int i = 1; i <= n; i++) vis[i] = false;
      for (auto [x, y] : Bits[j]) Adj[x][y].second--;
      if (dfs(1) != n) {
        for (auto [x, y] : Bits[j]) Adj[x][y].second++;
        ans += 1<<j;
      }
    }
    cout << ans << endl;
  }
}
