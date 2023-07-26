#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int Mxn = 5e3 + 1;

ll dist[Mxn];
int par[Mxn];

struct Edge {ll a, b, w;};

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m; cin >> n >> m;
  vector<Edge> Edges(m);
  for (auto &[a, b, w] : Edges) cin >> a >> b >> w;
  for (int i = 1; i <= n; i++) {
    dist[i] = 0, par[i] = -1;
  }
  int x = -1;
  for (int i = 0; i < n; i++) {
    x = -1;
    for (auto [a, b, w] : Edges) {
      if (dist[a] + w < dist[b]) {
        dist[b] = dist[a] + w; par[b] = a;
        x = b;
      }
    }
  }
  if (x == -1) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    for (int i = 0; i < n; i++) x = par[x];
    vector<int> C(1, x);
    for (int i = par[x]; i != x; i = par[i]) C.push_back(i);
    C.push_back(x);
    reverse(C.begin(), C.end());
    for (auto e : C) cout << e << " ";
  }
}


