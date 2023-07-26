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
 
int const Mxn = 1e5 + 1;
int const MOD = 1e9 + 7;
vector<vector<pair<int, int>>>  Adj;
vector<int> contribution, SSz, p;
int n;

void dfs(int node = 1, int parent = 1, int V = 0) {
  SSz[node] = 1;
  for (auto [child, v] : Adj[node]) {
    if (child == parent) continue;
    dfs(child, node, V);
    SSz[node] += SSz[child];
  }
  if (node == 1) return;
  contribution[V] = SSz[node]*(n - SSz[node]);
  contribution[V] %= MOD;
}

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    cin >> n; 
    Adj.clear(); Adj.resize(n + 1);
    contribution.resize(n - 1), SSz.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
      int x, y; cin >> x >> y;
      Adj[x].push_back({y, i});
      Adj[y].push_back({x, i});
    }

    dfs();
    sort(all(contribution), greater<int>());
    int m; cin >> m; p.clear(); p.resize(m);
    for (auto &e : p) cin >> e;
    sort(all(p), greater<int>());
    ll ans = 0;
    if (m <= n  - 1) {
      for (int i = 0; i < m; i++) {
        (ans += p[i]*contribution[i]) %= MOD;
      }
      for (int i = m; i < n - 1; i++) {
        (ans += contribution[i]) %= MOD;
      }
    } else {
      for (int i = 0; i < m - n - 1; i++) {
        (ans += contribution[0]*p[i]) %= MOD;
      }
      for (int i = 0; i < n - 1; i++) {
        (ans += contribution[i]*p[i - n - 1 + m]) %= MOD;
      }
    }
    cout << ans << endl;
  }
}
