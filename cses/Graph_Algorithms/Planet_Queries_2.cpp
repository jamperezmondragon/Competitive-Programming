#include <bits/stdc++.h>
using namespace std;
const int Mxn = 2e5 + 1;

int tin[Mxn], tout[Mxn], indegree[Mxn], nxt[Mxn], pos[Mxn], Sz[Mxn];
int leader[Mxn], dist[Mxn], cnt = 0, cycle[Mxn], ccnt = 0;

vector<int> Adj[Mxn];
bool vis[Mxn];

void dfs(int node, int ldr, int d = 0) {
  vis[node] = true; dist[node] = d;
  leader[node] = ldr;
  tin[node] = cnt++;
  for (auto child : Adj[node]) {
    if (vis[child]) continue;
    dfs(child, ldr, d + 1);
  }
  tout[node] = cnt++;
}

bool is_ancestor(int A, int B) {return (tin[A] <= tin[B] && tout[B] <= tout[A]);}

int main() {
  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> nxt[i];
    Adj[nxt[i]].push_back(i);
    indegree[nxt[i]]++;
  }
  stack<int> st;
  for (int i = 1; i <= n; i++) {
    if (indegree[i] == 0) st.push(i);
  }
  while (st.size()) {
    int node = st.top(); st.pop();
    if (--indegree[nxt[node]] == 0) st.push(nxt[node]);
  }
  memset(cycle, -1, sizeof(cycle));
  for (int i = 1; i <= n; i++) {
    if (indegree[i] == 0 || vis[i]) continue;

    cycle[i] = ccnt; pos[i] = 0, Sz[i] = 1; vis[i] = true;
    for (int j = 1, x = nxt[i]; x != i; x = nxt[x], j++) {
      Sz[i]++; vis[x] = true;
      cycle[x] = ccnt; pos[x] = j;
    }
    dfs(i, i);
    for (int x = nxt[i]; x != i; x = nxt[x]) {
      dfs(x, x);
      Sz[x] = Sz[i];
    }
    ccnt++;
  }
  while (q--) {
    int a, b; cin >> a >> b;
    if (cycle[leader[a]] != cycle[leader[b]]) {
      cout << -1 << '\n';
      continue;
    }
    if (leader[a] != a) {
      if (leader[b] == leader[a]) {
        if (!is_ancestor(b, a)) {
          cout << -1 << '\n';
        } else {
          cout << dist[a] - dist[b] << '\n';
        }
      } else {
        if (leader[b] != b) {
          cout << -1 << '\n';
        } else {
          cout << dist[a] + ((pos[leader[a]] < pos[b]) ? pos[b] - pos[leader[a]] : Sz[b] - (pos[leader[a]] - pos[b])) << '\n';
        }
      }
    } else {
      if (leader[b] != b) {
        cout << -1 << '\n';
      } else {
        if (pos[a] <= pos[b]) {
          cout << pos[b] - pos[a] << '\n';
        } else {
          cout << Sz[a] - (pos[a] - pos[b]) << '\n';
        }
      }
    }
  }
}
