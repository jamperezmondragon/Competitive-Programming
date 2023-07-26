#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int Mxn = 1e5 + 1;
const int MOD = 1e9 + 7;
vector<vector<int>> Adj;
int indegree[Mxn];
ll dp[Mxn];
vector<int> topo;

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n, m; cin >> n >> m;
  Adj.assign(n + 1, {});
  for (int i = 0; i < m; i++) {
    int x, y; cin >> x >> y;
    Adj[x].push_back(y);
    indegree[y]++;
  }
  stack<int> st;
  for (int i = 1; i <= n; i++) {
    if (!indegree[i]) st.push(i);
  }
  while (st.size()) {
    int x = st.top(); st.pop();
    for (auto child : Adj[x]) {
      if (--indegree[child] == 0) st.push(child);
    }
    topo.push_back(x);
  }
  dp[n] = 1;
  reverse(topo.begin(), topo.end());
  for (auto e : topo) {
    for (auto child : Adj[e]) {
      (dp[e] += dp[child]) %= MOD;
    }
  }
  cout << dp[1] << '\n';

}

