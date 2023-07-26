#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const ll MOD = 1e9 + 7;
ll dp[20][1<<20];
int n;
vector<int> g[20];

ll solve(int node = 0, int mask = (1<<n) - 2)  {

  if (node == n - 1 && mask != 0) return 0;
  if (dp[node][mask] != -1) return dp[node][mask];
  dp[node][mask] = 0;
  for (auto v : g[node]) {
    if ((mask>>v)&1) (dp[node][mask] += solve(v, mask^(1<<v))) %= MOD;
  }
  return dp[node][mask];
}
int main() {
  int m; cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int x, y; cin >> x >> y; x--, y--;
    g[x].push_back(y);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (1<<n); j++) {
      dp[i][j] = -1;
    }
  }
  dp[n - 1][0] = 1;
  cout << solve() << endl;
}
