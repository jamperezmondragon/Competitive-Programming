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
bool vis[Mx]; bool flag = false;
int color[Mx];

void dfs(int node, int c) {
  if (vis[node]) {
    if (color[node] != c) flag = true;
    return;
  }
  color[node] = c; vis[node] = true;
  for (auto e : adjlist[node]) {
    dfs(e, ((c == 1) ? 2 : 1));
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
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) dfs(i, 1); 
  }

  if (flag) {
    cout << "IMPOSSIBLE"; return 0;
  }
  for (int i = 1; i <= n; i++) {
    cout << color[i] << " ";
  }

}
