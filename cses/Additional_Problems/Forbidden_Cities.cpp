#include <bits/stdc++.h>
using namespace std;
const int Mxn = 1e5 + 1;
const int LOGN = 18;

vector<int> g[Mxn];
bitset<Mxn> vis;
int ST[LOGN + 1][Mxn];
int cnt = 0, dp[Mxn], depth[Mxn], tin[Mxn], tout[Mxn];

void dfs(int node = 1, int parent = 1) {
  vis[node] = 1; ST[0][node] = parent;
  depth[node] = dp[node] = depth[parent] + 1;
  for (int i = 1; i <= LOGN; i++) {
    ST[i][node] = ST[i - 1][ST[i - 1][node]];
  }
  tin[node] = cnt++;
  for (auto child : g[node]) {
    if (child == parent) continue;
    if (!vis[child]) {
      dfs(child, node); dp[node] = min(dp[child], dp[node]);
    } else {
      if (depth[node] > depth[child]) dp[node] = min(depth[child], dp[node]);
    }
  }
  tout[node] = cnt++;
}

bool is_ancestor(int A, int B) {
  return (tin[A] <= tin[B] && tout[B] <= tout[A]);
}

int LA(int A, int k) {
  for (int i = 0; i <= LOGN; i++) {
    if ((k>>i)&1) A = ST[i][A];
  }
  return A;
}

int LCA(int A, int B) {
  if (depth[A] < depth[B]) swap(A, B);
  A = LA(A, depth[A] - depth[B]);
  if (A == B) return A;
  for (int i = LOGN; i >= 0; i--) {
    if (ST[i][A] != ST[i][B]) A = ST[i][A], B = ST[i][B];
  }
  return ST[0][A];
}

int main() {
  int n, m, q; cin >> n >> m >> q;
  for (int i = 0; i < m; i++) {
    int a, b; cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  depth[1] = 1; dfs();

  while (q--) {
    int a, b, c; cin >> a >> b >> c;
    if (depth[a] < depth[b]) swap(a, b);
    int lca = LCA(a, b);
    if (c == a || c == b) {
      cout << "NO\n"; continue;
    }
    if (!is_ancestor(c, a) && !is_ancestor(c, b)) {
      cout << "YES\n"; continue;
    }
    if (is_ancestor(c, lca) && c != lca) {
      cout << "YES\n"; continue;
    }
    if (lca == c) {
      if (c == 1) {
        cout << "NO\n"; continue;
      }
      int x = LA(a, depth[a] - depth[c] - 1);
      int y = LA(b, depth[b] - depth[c] - 1);
      if (dp[x] < depth[c] && dp[y] < depth[c]) cout << "YES\n";
      else cout << "NO\n";
      continue;
    }
    if (is_ancestor(c, a)) {
      int x = LA(a, depth[a] - depth[c] - 1);
      if (dp[x] < depth[c]) cout << "YES\n";
      else cout << "NO\n";
      continue;
    }
    if (is_ancestor(c, b)) {
      int x = LA(b, depth[b] - depth[c] - 1);
      if (dp[x] < depth[c]) cout << "YES\n";
      else cout << "NO\n";
      continue;
    }
  }
}
