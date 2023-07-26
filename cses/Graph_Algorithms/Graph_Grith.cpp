#include <bits/stdc++.h>
using namespace std;
int const Mxn = 25e2 + 10;
int n, m, ans = 2*Mxn, x, y;
vector<vector<int>> Adj(Mxn);

int BFS(int v, int res = 2*Mxn) {
  queue<int> Q;
  Q.push(v);
  vector<int> dist(n + 1, -1);
  dist[v] = 0;
  while (!Q.empty()) {
    int node = Q.front(); Q.pop();
    for (auto child : Adj[node]) {
      if (dist[child] == -1) {
        Q.push(child); dist[child] = dist[node] + 1;
      } else if (dist[child] >= dist[node]) {
        res = min(res, dist[child] + dist[node] + 1);
      }
    }
  }

  return res;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> x >> y;
    Adj[x].push_back(y);
    Adj[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    ans = min(BFS(i), ans);
  }
  cout << (ans == 2*Mxn ? -1 : ans) << endl;
}
