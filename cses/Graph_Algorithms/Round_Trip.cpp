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
int ans; int Prev[Mx]; bool vis[Mx]; bool flag = false;

void dfs(int node) {
  if (vis[node]) {
    ans = node; flag = true; return;
  }
  vis[node] = true;
  for (auto e : adjlist[node]) {
    if (e == node) continue;
    Prev[e] = node; dfs(e);
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
  for (int i = 0; i < n; i++) {
    if (!vis[i]) dfs(i);
  }
  if (!flag) {
    cout << "IMPOSSIBLE"; return 0;
  }
  vector<int> vals = {ans}; int curr = Prev[ans];
  while (curr != ans) vals.push_back(curr), curr = Prev[curr];
  cout << (int)vals.size() << "\n";
  for (auto e : vals) cout << e << " ";
}
