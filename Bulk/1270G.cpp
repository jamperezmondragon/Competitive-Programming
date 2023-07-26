#include <bits/stdc++.h>
using namespace std;
int const Mxn = 1e6 + 10;
int f[Mxn];
int vis[Mxn];

int main() {
  cin.tie(0), ios_base::sync_with_stdio(0);
  int tt; cin >> tt;
  while (tt--) {
    int n, curr = 1, cnt = 0; cin >> n;
    for (int i = 1, x; i <= n; i++) {
      cin >> x; f[i] =  i - x; vis[i] = 0;
    }
    while (!vis[curr]) {
      vis[curr] = cnt++, curr = f[curr];
    }
    cout << cnt - vis[curr] << "\n";
    while (vis[curr] != -1) {
      vis[curr] = -1; curr = f[curr]; cout << curr << " ";
    }
    cout << "\n";
  }
}
