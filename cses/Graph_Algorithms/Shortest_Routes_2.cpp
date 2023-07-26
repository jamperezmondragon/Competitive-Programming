#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const ll INF = 1e17;
const int Mxn = 5e2 + 1;
ll dist[Mxn][Mxn];



int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m, q; cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dist[i][j] = INF;
      if (i == j) dist[i][j] = 0;
    }
  }
  for (int i = 0; i < m; i++) {
    ll x, y, c; cin >> x >> y >> c;
    dist[x][y] = dist[y][x] = min(dist[x][y], c);
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  while (q--) {
    int x, y; cin >> x >> y;
    if (dist[x][y] == INF) cout << -1 << '\n';
    else cout << dist[x][y] << '\n';
  }
}
