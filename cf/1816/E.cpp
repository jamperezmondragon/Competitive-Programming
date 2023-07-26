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
 
int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    int n, m; cin >> n >> m;
    vii g, V;
    g.resize(n + 1);
    V.resize(n + 1);
    for (int i = 0; i < m; i++) {
      int x, y; cin >> x >> y;
      if (x == 1) continue;
      g[y].push_back(x);
    }
    queue<int> Q; Q.push(1);
    vector<int> depth(n + 1, -1);
    depth[1] = 1;
    while (sz(Q)) {
      int node = Q.front(); Q.pop();
      V[depth[node]].push_back(node);
      for (auto child : g[node]) {
        if (depth[child] != -1) continue;
         depth[child] = depth[node] + 1;
         Q.push(child);
      }
    }
    bool flag = false;
    int len = 0;
    for (int i = 1; i <= n; i++) {
      len += depth[i];
      if (depth[i] == -1) flag = true;
    }
    if (flag) {
      cout << "INFINITE\n";
    } else {
      cout << "FINITE\n" << len << '\n';
      for (int i = 1; i <= n; i++) {
        for (int j = n; j >= i; j--) {
          for (auto e : V[j]) cout << e << " ";
        }
      }
      cout << '\n';
    }
  }
}
