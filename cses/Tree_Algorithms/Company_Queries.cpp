#include <bits/stdc++.h>
using namespace std;
int const Mxn = 2e5 + 10;
int const LOGN = 23;
int SparseTable[Mxn][LOGN + 1];
int n, q, x, y;


int main() {
  cin >> n >> q;
  memset(SparseTable, 0, sizeof(SparseTable));
  for (int i = 2; i <= n; i++) {
    cin >> SparseTable[i][0];
    for (int j = 1; j < LOGN; j++) {
      SparseTable[i][j] = SparseTable[SparseTable[i][j - 1]][j - 1];
    }
  }
  while (q--) {
    cin >> x >> y;
    for (int i = 0; i < LOGN; i++) {
      if ((y>>i)&1) x = SparseTable[x][i];
    }
    cout << ((x) ? x : -1) << endl;
  }
}
