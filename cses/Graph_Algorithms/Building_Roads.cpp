#include <bits/stdc++.h>
using namespace std;
/* Informative
* ==============
* Status: 
* link del problema: 
* submission:
*/
/*
* Comments
* =========
*
*/
/* Analisis
* ==========
*
*/
const int Mx = 1e5+5;
vector<vector<int>> adjlist;
bool vis[Mx];

void dfs(int node) {
  vis[node] = true;
  for (auto e : adjlist[node]) {
    if (vis[e]) continue;
    dfs(e);
  }
}
int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  int n, m; cin >> n >> m; adjlist.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int x, y; cin >> x >> y;
    adjlist[x].push_back(y);
    adjlist[y].push_back(x);
  }
  vector<int> cc;
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    dfs(i); cc.push_back(i);
  }
  cout << (int)cc.size() - 1 << "\n";
  for (int i = 0; i < (int)cc.size() - 1; i++) {
    cout << cc[i] << " " << cc[i + 1] << "\n";
  }
}
