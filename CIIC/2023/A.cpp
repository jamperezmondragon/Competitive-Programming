#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int Mxn = 2e5 + 1; 

vector<ll> adj[Mxn], G[Mxn<<1];
set<array<ll, 3>> g[Mxn];
ll val[Mxn];
ll Ans[Mxn<<1];

//dsu
set<pair<ll, ll>> S;
int cnt = Mxn;
int leader[Mxn], root[Mxn];
ll sum[Mxn];
set<array<ll, 3>> hojas[Mxn];

void make_set(int x) {
  leader[x] = x; hojas[x] = g[x]; sum[x] = val[x]; root[x] = x;
  S.insert({sum[x], x});
}
int find(int x) {return ((leader[x] == x) ? x : (leader[x] = find(leader[x])));}

void unite(int u, int v) {
  int U = find(u), V = find(v);
  if (U == V) return;
  if (S.count({sum[U], U})) S.erase({sum[U], U});
  if (S.count({sum[V], V})) S.erase({sum[V], V});
  if (size(hojas[U]) < size(hojas[V])) swap(U, V);
  for (auto e : hojas[V]) hojas[U].insert(e);
  leader[V] = U; sum[U] += sum[V];
  G[cnt].push_back(root[U]);
  G[cnt].push_back(root[V]);
  G[root[U]].push_back(cnt);
  G[root[V]].push_back(cnt);
  root[U] = cnt++;
  S.insert({sum[U], U});
}

void dfs(int node, int parent = -1, ll ans = -1) {
  if (Ans[node] != -1) ans = Ans[node];
  Ans[node] = ans;
  for (auto child : G[node]) {
    if (child == parent) continue;
    dfs(child, node, ans);
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  for (int i = 1; i < n; i++) {
    ll x, y; cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  for (ll i = 1; i <= n; i++) cin >> val[i];
  for (ll i = 1; i <= n; i++) {
    for (auto e : adj[i]) {
      g[i].insert({val[e], e, i});
    }
  }
  for (int i = 1; i <= n; i++) make_set(i);
  for (int i = 0; i < (Mxn<<1); i++) Ans[i] = -1;
  while (size(S)) {
    auto it = S.begin();
    auto [x, e] = *it;
    if (size(hojas[find(e)]) == 0) break;
    auto it1 = hojas[find(e)].begin();
    auto [w, v, u] = *it1;
    S.erase({x, e});
    if (val[v] < x) {
      unite(e, v);
      hojas[find(e)].erase({val[v], v, u});
      hojas[find(e)].erase({val[u], u, v});
    } else {
      Ans[root[find(e)]] = sum[find(u)];
    }
  }
  if (size(S) == 1) Ans[cnt - 1] = sum[find(1)];
  for (int i = 1; i <= n; i++) {
    if (Ans[i] == -1) dfs(root[find(i)]);
    cout << Ans[i] << " ";
  }
  cout << endl;
}
