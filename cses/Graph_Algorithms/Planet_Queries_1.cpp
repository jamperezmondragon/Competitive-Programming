#include <bits/stdc++.h>
using namespace std;
const int Mxn = 2e5 + 1;
const int LOGN = 32;
int ST[LOGN][Mxn];

int main() {
  cin.tie(0), ios_base::sync_with_stdio(0);
  int n, q; cin >> n >> q;
  for (int i = 1; i <= n; i++) cin >> ST[0][i];
  for (int i = 1; i < LOGN; i++) {
    for (int j = 1; j <= n; j++) {
      ST[i][j] = ST[i - 1][ST[i - 1][j]];
    }
  }
  while (q--) {
    int x, k; cin >> x >> k;
    for (int i = 0; i < LOGN; i++) {
      if ((k>>i)&1) x = ST[i][x];
    }
    cout << x << '\n';
  }
}
