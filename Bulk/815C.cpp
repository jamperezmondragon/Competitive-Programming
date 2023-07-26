#include <bits/stdc++.h>
using namespace std;
const int Mxn = 5e3 + 1;

int sz[Mxn];
int A[Mxn], B[Mxn], f[Mxn][Mxn], dp[Mxn][Mxn];
vector<int> g[Mxn];

void dfs(int node = 1, int parent = 0) {

  dp[node][0] = f[node][0] = 0;
  dp[node][1] = A[node] - B[node];
  f[node][1] = A[node];
  sz[node] = 1;

  for (auto child : g[node]) {
    if (child == parent) continue;
    dfs(child, node);
    for (int i = sz[node]; i >= 0; i--) {
      for (int j = 0; j <= sz[child]; j++) {
        f[node][i + j] = min(f[node][i + j], f[node][i] + f[child][j]);
        if (i != 0) dp[node][i + j] = min(dp[node][i + j], dp[node][i] + dp[child][j]);
      }
    }
    sz[node] += sz[child];
    for (int i = 0; i <= sz[node]; i++) dp[node][i] = min(dp[node][i], f[node][i]);
  }
}

int main() {
  int n, b; cin >> n >> b;
  for (int i = 1; i <= n; i++) {
    cin >> A[i] >> B[i];
    if (i == 1) continue;
    int x; cin >> x;
    g[x].push_back(i);
    g[i].push_back(x);
  }
  for (int i = 0; i < Mxn; i++) {
    for (int j = 0; j < Mxn; j++) {
      dp[i][j] = f[i][j] = 1e9;
    }
  }
  dfs();
  for (int i = 1; i <= n; i++) {
    cout << i << " " << sz[i] << endl;
    for (int j = 0; j <= sz[i]; j++) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
    for (int j = 0; j <= sz[i]; j++) {
      cout << f[i][j] << " ";
    }
    cout << endl;
  }
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    if (dp[1][i] <= b) ans = i;
  }
  cout << ans << endl;
}
