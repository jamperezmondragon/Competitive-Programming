#include <bits/stdc++.h>
using namespace std;
const int Mxn = 1e5 + 1;
int indegree[Mxn];
vector<vector<int>> Adj;

int main() {
  int n, m; cin >> n >> m;
  Adj.assign(n + 1, {});
  for (int i = 0; i < m; i++) {
    int x, y; cin >> x >> y;
    Adj[y].push_back(x); indegree[y]++;
  }
  priority_queue<int> pq;
  for (int i = 1; i <= n; i++) {
    if (indegree[i]) continue;
    pq.push(i);
  }
  while (pq.size()) {
    int x = pq.top(); pq.pop();
    for (auto child : Adj[x]) {
      if (--indegree[child]) continue;
      pq.push(child);
    }
    cout << x << " ";
  }
  cout << "\n";
}
