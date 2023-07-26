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

vector<vector<pair<int, int>>> g;
int ans;

void dfs(int node = 1, int parent = 0, int cnt = 1, int last = 0) {
  ans = max(ans, cnt);
  for (auto [child, w] : g[node]) {
    if (child == parent) continue;
    dfs(child, node, cnt + ((last > w) ? 1 : 0), w);
  }
}
 
int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    int n; cin >> n;
    g.clear(); g.resize(n + 1);
    ans = 1;
    for (int i = 1; i < n; i++) {
      int x, y; cin >> x >> y;
      g[x].push_back({y, i});
      g[y].push_back({x, i});
    }
    dfs();
    cout << ans << endl;
  }
}
