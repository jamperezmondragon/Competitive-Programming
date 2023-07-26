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
int Sz[Mxn];
int A[Mxn];
int P[Mxn];
vector<int> g[Mxn];
bool compare(int & x, int & y) {return Sz[x] > Sz[y];}
vector<set<int, compare>> G;

int dfs(int node = 1, int parent = 1) {
  Sz[node] = 1;
  P[node] = parent;
  for (auto child : g[node]) {
    if (child == parent) continue;
    G[node].insert(child);
    Sz[node] += dfs(child, node);
    A[node] += A[child];
  }
  return Sz[node];
}

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  int n, q; cin >> n >> q;
  G.resize(n + 1);
  for (int i = 0; i < n; i++) cin >> A[i + 1];
  for (int i = 1; i < n; i++) {
    int x, y; cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  while (q--) {
    int t, x; cin >> t >> x;
    if (t - 1) {
      if (sz(G[x]) == 0) continue;
      auto y = G[x].begin();
      Sz[x] -= Sz[*y];
      Sz[*y] += Sz[x];
      A[x] -= A[*y];
      A[*y] += A[x];
      G[P[x]].insert(*y);
      G[P[x]].erase(x);
      P[*y] = P[x], P[x] = *y;
      G[*y].insert(x);
      G[x].erase(y);
    } else {
      cout << A[x] << endl;
    }
  }
}
