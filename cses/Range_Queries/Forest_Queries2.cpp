#include <bits/stdc++.h>
using namespace std;
int const Mxn = 1e3 + 10;
int grid[Mxn][Mxn];
int N, M, x, a, b, c, d;

int BIT[Mxn][Mxn];
void upd(int i, int j, int delta) {
  for (; i < Mxn; i += i&(-i)) {
    for (int k = j; k < Mxn; k += k&(-k)) {
      BIT[i][k] += delta;
    }
  }
}
int query(int i, int j, int ans = 0) {
  for (; i > 0; i -= i&(-i)) {
    for (int k = j; k > 0; k -= k&(-k)) {
      ans += BIT[i][k];
    }
  }
  return ans;
}

int main() {
  cin >> N >> M;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      char cc; cin >> cc; grid[i][j] = (cc == '*');
      if (grid[i][j]) upd(i, j, 1);
    }
  }
  while (M--) {
    cin >> x;
    if (x == 1) {
      cin >> a >> b;
      grid[a][b] ^= 1;
      if (grid[a][b]) upd(a, b, 1);
      else upd(a, b, -1);
    } else {
      cin >> a >> b >> c >> d;
      x = query(c, d) - query(c, b - 1) - query(a - 1, d) + query(a - 1, b - 1);
      cout << x << endl;
    }
  }
}
