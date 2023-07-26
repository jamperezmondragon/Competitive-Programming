#include <bits/stdc++.h>
using namespace std;

const int Mxn = 1e5 + 1;
int indegree[Mxn];
vector<vector<int>> Adj;

int main() {
  cin.tie(0), ios_base::sync_with_stdio(0);
  int n, m; cin >> n >> m;
  Adj.assign(n + 1, {});
  for (int i = 0; i < m; i++) {
    int x, y; cin >> x >> y;
    Adj[x].push_back(y); indegree[y]++;
  }
  stack<int> st; vector<int> toposort;
  for (int i = 1; i <= n; i++) {
    if (indegree[i]) continue;
    st.push(i);
  }
  while (st.size()) {
    int x = st.top(); st.pop();
    toposort.push_back(x);
    for (auto child : Adj[x]) {
      if (--indegree[child] == 0) st.push(child);
    }
  }
  if (toposort.size() != n) {
    cout << "IMPOSSIBLE\n";
  } else {
    for (auto e : toposort) {
      cout << e << " ";
    }
    cout << '\n';
  }
}
