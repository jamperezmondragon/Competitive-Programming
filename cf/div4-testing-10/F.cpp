#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pi = pair<int, int>;
using vii = vector<vector<int>>;
using mii = map<int, int>;
#define in(a) for (auto &e : a) cin >> e
#define sz(x) int((x).size())
#define all(a) a.begin(), a.end()
#define ptp partition_point
#define F first
#define S second
#define Testcase ll t; cin >> t; while (t--)
#define nl "\n"
#define m_p make_pair
 
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
int bfs(int x, vector<vector<int>> & g, vector<int> & val, vector<bool> & vis)  {
  int ans = 0;
  queue<int> Q; Q.push(x);
  vis[x] = true;
  while (sz(Q)) {
    int node = Q.front(); Q.pop();
    ans += val[node];
    for (auto child : g[node]) {
      if (vis[child]) continue;
       vis[child] = true; Q.push(child);
    }
  }
  return ans;
}
int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    int n, m; cin >> n >> m; vi val(n*m); vector<vector<int>> g(n*m, vector<int>()); vector<bool> vis(n*m, false);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> val[m*i + j];
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        for (int k = 0; k < 4; k++) {
          if (dx[k] + i == n || dx[k] + i == -1 || dy[k] + j == m || dy[k] + j == -1) continue;
          int x = m*i + j, y = m*(dx[k] + i) + dy[k] + j;
          if (!val[x] || !val[y]) continue;
          g[x].push_back(y);
          g[y].push_back(x);
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < n*m; i++) {
      if (!vis[i]) ans = max(ans, bfs(i, g, val, vis));
    }
    cout << ans << endl;
  }
}
