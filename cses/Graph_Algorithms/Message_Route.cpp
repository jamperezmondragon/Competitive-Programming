#include <bits/stdc++.h>
using namespace std;
int const Mxn = 1e5 + 10;
int n, m, x, y;
vector<vector<int>> Adj(Mxn);

void bfs() {
  vector<int> parent(n + 1, -1), ans;
  queue<int> Q;
  parent[1] = 1; Q.push(1);
  while (!Q.empty()) {
    int node = Q.front(); 
    for (auto child : Adj[node]) {
      if (parent[child] != -1) continue;
      parent[child] = node; Q.push(child);
    }
    Q.pop();
  }
  int aux = n;
  if (parent[n] == -1) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }
  while (aux != 1) {
    ans.push_back(aux); aux = parent[aux];
  }
  ans.push_back(1);
  reverse(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (auto e : ans) cout << e << " ";
  return;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> x >> y;
    Adj[x].push_back(y);
    Adj[y].push_back(x);
  }
  bfs();
}
