#include <bits/stdc++.h>
using namespace std;
const int Mxn = 1e5 + 1;
const int LOGN = 18;

int ans[Mxn];
int A[Mxn];
vector<int> g[Mxn];
stack<pair<int, int>> st;
pair<int, int> E[Mxn];
int dist[Mxn];

int bfs(int v, int src = 1) {
  if (A[v] != -1) return A[v];
  for (int i = 0; i < Mxn; i++) dist[i] = -1;
  dist[src] = 0;
  queue<int> Q; Q.push(src);
  while (size(Q)) {
    auto node = Q.front(); Q.pop();
    for (auto child : g[node]) {
      if (dist[child] != -1) continue;
      dist[child] = dist[node] + 1;
      A[v] = max(A[v], dist[child]);
      Q.push(child);
    }
  }
  return A[v];
}


int main() {
  int n, m, q; cin >> n >> m >> q;
  for (int i = 0; i <= q; i++) A[i] = -1;
  for (int i = 0; i < m; i++) {
    int x, y; cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 1; i <= q; i++) {
    int x, y; cin >> x >> y;
    E[i] = {x, y};
  }
  //cout << bfs(0) << " "; 
  //for (int i = 1; i <= q; i++) {
      //auto [x, y] = E[i];
      //g[x].push_back(y);
      //g[y].push_back(x);
      //st.emplace(x, y);
    //cout << bfs(i) << " ";
  //}
  //cout << endl;
  //while (size(st)) {
    //auto [x, y] = st.top(); st.pop();
    //g[x].pop_back();
    //g[y].pop_back();
  //}
  for (int i = 0; i <= q; i++) A[i] = -1;
  int val = 1;
  ans[0] = bfs(0);
  g[E[1].first].push_back(E[1].second);
  g[E[1].second].push_back(E[1].first);
  while (val <= q) {
    int curr = val;
    for (int j = LOGN; j >= 0; j--) {
      if (curr + (1<<j) > q) continue;
      for (int k = curr + 1; k <= curr + (1<<j); k++) {
        auto [x, y] = E[k];
        g[x].push_back(y);
        g[y].push_back(x);
        st.push({x, y});
      }
      if (A[val - 1] <= 2*bfs(curr + (1<<j))) curr += (1<<j);
      else {
        for (int k = curr + 1; k <= curr + (1<<j); k++) {
          auto [x, y] = st.top(); st.pop();
          g[x].pop_back();
          g[y].pop_back();
        }
      }
    }
    ans[curr] = bfs(curr);
    for (int j = val; j < curr; j++) ans[j] = 2*A[curr];
    val = curr + 1;
    auto [x, y] = E[val];
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 0; i <= q; i++) {
    cout << ans[i] << " ";
  }
}
