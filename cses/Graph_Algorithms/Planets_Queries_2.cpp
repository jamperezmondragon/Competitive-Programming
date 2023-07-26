#include <bits/stdc++.h>
using namespace std;
const int Mxn = 2e5 + 1;

vector<vector<int>> Adj;
int cnt = 0, nxt[Mxn], indegree[Mxn], tin[Mxn], tout[Mxn], depth[Mxn];
int cycle[Mxn], pos[Mxn], color[Mxn];
int jefe[Mxn];

void dfs(int node, int jefe_tribal,  int D = 0) {
  depth[node] = D;
  jefe[node] = jefe_tribal;
  tin[node] = cnt++;
  for (auto child : Adj[node]) {
    if (indegree[child]) continue;
    dfs(node, jefe_tribal, D + 1);
  }
  tout[node] = cnt;
}

int main() {
  int n, q; cin >> n >> q;
  Adj.assign(n + 1, {});
  for (int i = 1; i <= n; i++) {
    cin >> nxt[i];
    Adj[nxt[i]].push_back(i);
    indegree[nxt[i]]++;
  }
  stack<int> st;
  for (int i = 1; i <= n; i++) {
    if (indegree[i]) continue;
    st.push(i);
  }
  while (st.size()) {
    int x = st.top(); st.pop();
    if (--indegree[nxt[x]]) continue;
    st.push(nxt[x]);
  }
  for (int i = 1; i <= n; i++) {
    cycle[i] = indegree[i];
    if (!indegree[i]) continue;
    dfs(i, i);
  }
  int cnt_c = 0;

  for (int i = 1; i <= n; i++) {
    if (!indegree[i]) continue;
    indegree[i] = 0; color[i]  = ++cnt_c; pos[i] = 0;
    for (int x = nxt[i]; x != i; x = nxt[x]) {
      cycle[i]++; color[x] = cnt_c;
    }
    for (int x = nxt[i], y = 0; x != i; x = nxt[x]) {
      cycle[x] = cycle[i]; pos[x] = ++y;
      indegree[x] = 0;
    }
  }
  while (q--) {
    int x, y; cin >> x >> y;
    if (cycle[x] == 0 && cycle[y] == 0) {
      if (tin[y] < tin[x] && tout[x] <= tout[y]) {
        cout << depth[x] - depth[y] << '\n';
      } else {
        cout << -1 << '\n';
      }
    } else {
      if (cycle[y] == 0) {
        cout << -1 << '\n';
      } else {
        int z = jefe[x]; 
        if (color[z] != color[y]) {
          cout << -1 << '\n';
        } else {
          if (pos[z] < pos[y]) {
            cout << depth[x] + pos[y] - pos[z] << '\n';
          } else {
            cout << depth[x] + cycle[z] - pos[z] + pos[y] << '\n';
          }
        }
      }
    }
  }
}
