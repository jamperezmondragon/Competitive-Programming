#include <bits/stdc++.h>
using namespace std;
const int Mxn = 1e5 + 1;

vector<int> g[Mxn];
int deg[Mxn], vals[Mxn], dp[Mxn], offset[Mxn];

map<int, int> dfs(int node = 1, int parent = 0) {
  vals[node] ^= vals[parent];
  map<int, int> A; 
  offset[node] = dp[node] = 0;
  int cnt = 1;

  if (deg[node] == 1 && node != 1) {
    A[vals[node]] = 1; return A;
  }

  for (auto child : g[node]) {
    if (child == parent) continue;
    auto B = dfs(child, node);
    dp[node] += dp[child] + 1;
    if (size(A) < size(B)) swap(A, B), swap(offset[node], offset[child]);
    for (auto [x, y] : B) {
      if (y <= offset[child]) continue;
      if (A[x] < offset[node]) A[x] = offset[node];
      A[x] += y - offset[child];
      cnt = max(A[x] - offset[node], cnt);
    }
  }

  offset[node] += cnt - 1; dp[node] -= cnt;
  return A;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) cin >> vals[i];
  for (int i = 1; i < n; i++) {
    int x, y; cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
    deg[x]++; deg[y]++;
  }
  auto A = dfs();
  if (A[0] <= offset[1]) cout << dp[1] + 1 << endl;
  else cout << dp[1] << endl;
}
