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

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  int n, m; cin >> n >> m; vector<int> prev(n + 1, 0), ans;
  vector<vector<int>> adjlist(n + 1);
  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    adjlist[x].push_back(y);
    adjlist[y].push_back(x);
  }
  queue<int> Q;
  Q.push(1); prev[1] = 0;
  while (!Q.empty()) {
    int f = Q.front();
    Q.pop();
    for (auto e : adjlist[f]) {
      if (prev[e] != 0) continue;
      Q.push(e); prev[e] = f;
    }
  }
  if (prev[n] == 0) {
    cout << "IMPOSIBLE"; return 0;
  } 
  int curr = n;
  while (curr != 1) {
    ans.push_back(curr);
    curr = prev[curr];
  }
  ans.push_back(1);
  reverse(ans.begin(), ans.end());
  cout << ans.size() << "\n";
  for (auto e : ans) cout << e << " ";
}
