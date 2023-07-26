#include <bits/stdc++.h>
using namespace std;

// node for {i, j} = i*m + j;
// border if node%m == 0, m - 1 or node/m == 0, n - 1

const int Mxn = 1e6 + 1;
vector<pair<int, char>> Adj[Mxn];
int t[Mxn];
char value[Mxn];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {-1, 1, 0, 0};
char val[4] = {'L', 'R', 'D', 'U'};
int dist[Mxn];
int parent[Mxn];
char path[Mxn];
int root;
int last; 
bool flag = false;

int main() {
  int n, m; cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> value[i*m + j];
    }
  }
  queue<int> Q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      dist[i*m + j] = -1;
      t[i*m + j] = Mxn;
      if (value[i*m + j] == '#') continue;
      if (value[i*m + j] == 'A') root = i*m + j;
      if (value[i*m + j] == 'M') {
        Q.push(i*m + j); t[i*m + j] = 0;
      }

      for (int k = 0; k < 4; k++) {
        if (i + dx[k] == -1 || i + dx[k] == n) continue;
        if (j + dy[k] == -1 || j + dy[k] == m) continue;
        if (value[(i + dx[k])*m + j + dy[k]] == '#') continue;
        Adj[i*m + j].push_back({(i + dx[k])*m + j + dy[k], val[k]});
      }

    }
  }

  while (Q.size()) {
    int node = Q.front(); Q.pop();
    for (auto [child, W] : Adj[node]) {
      if (t[child] != Mxn) continue;
      t[child] = t[node] + 1;
      Q.push(child);
    }
  }

  Q.push(root); dist[root] = 0; 
  while (Q.size()) {
    int node = Q.front(); Q.pop();
    if (node%m == 0 || node%m == m - 1 || node/m == 0 || node/m == n - 1) {
      flag = true; last = node;
    }
    for (auto [child, W] : Adj[node]) {
      if (dist[child] != -1 || t[child] <= dist[node] + 1) continue;
      dist[child] = dist[node] + 1;
      parent[child] = node;
      path[child] = W;
      Q.push(child);
    }
  }
  
  if (!flag) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    string s; 
    for (; last != root; last = parent[last]) {
      s += path[last];
    }
    reverse(s.begin(), s.end());
    cout << s.size() << '\n';
    cout << s << '\n';
  }

}
