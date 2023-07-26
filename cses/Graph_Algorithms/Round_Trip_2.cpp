#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vii = vector<vi>;
int const Mxn = 1e5 + 1;

vii g;
vi vis, euler, tin;
vector<pair<int, int>> back_edges;
bool flag = false;

void dfs(int node) {
  vis[node] = 1;
  tin[node] = (int)euler.size();
  euler.push_back(node);
  for (auto child : g[node]) {
    if (vis[child] == 2) continue;
    if (vis[child] == 1) back_edges.push_back({node, child});
    else dfs(child);
  }
  vis[node] = 2;
  euler.push_back(node);
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m; cin >> n >> m;
  g.resize(n + 1);
  vis.assign(n + 1, 0);
  tin.resize(n + 1);
  for (int i = 0; i < m; i++) {
    int x, y; cin >> x >> y;
    g[x].push_back(y);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) dfs(i);
  }
  if (back_edges.size() == 0) cout << "IMPOSSIBLE\n";
  else {
    int x, y; 
    tie(x, y) = back_edges.back();
    if (tin[x] > tin[y]) swap(x, y);
    stack<int> st;
    st.push(x);
    for (int i = tin[x] + 1; i <= tin[y]; i++) {
      if (euler[i] == st.top()) st.pop();
      else st.push(euler[i]);
    }
    vi ans;
    ans.push_back(x);
    for (; st.size(); st.pop()) ans.push_back(st.top());
    reverse(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (auto e : ans) cout << e << " ";
  }
} 


