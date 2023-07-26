#include <bits/stdc++.h>
using namespace std;

const int Mxn = 1e5 + 1;
int depth[Mxn];
bool vis[Mxn];
int dp[Mxn];
int A[2*Mxn], B[2*Mxn], C[2*Mxn];
vector<pair<int, int>> g[Mxn];

void dfs(int node = 1, int parent = 1) {
  vis[node] = true;
  depth[node] = depth[parent] + 1;
  for (auto [child, idx] : g[node]) {
    if (vis[child]) {
      if (depth[child] < depth[node] && child != parent) {
        dp[child]--, dp[node]++; C[idx] = 1;
      }
      continue;
    }
    dfs(child, node); dp[node] += dp[child];
  }
}

int main() {
  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> A[i] >> B[i];
    g[A[i]].push_back({B[i], i});
    g[B[i]].push_back({A[i], i});
  }
  dfs();
  int aux = 1;
  for (int i = 2; i <= n; i++) {
    aux &= (dp[i] != 0);
  }
  if (!aux) {
    cout << "IMPOSSIBLE\n";
  } else {
    for (int i = 0; i < m; i++) {
      if (C[i]) {
        if (depth[A[i]] < depth[B[i]]) swap(A[i], B[i]);
      } else {
        if (depth[A[i]] > depth[B[i]]) swap(A[i], B[i]);
      }
      cout << A[i] << " " << B[i] << endl;
    }
  }

}
