#include <bits/stdc++.h>
using namespace std;
const int LOGN = 20;
const int Mxn = 1e6 + 1;

int ST[LOGN + 1][Mxn + 1];
int A[Mxn + 1];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q; cin >> n >> q;
  memset(A, Mxn, sizeof(A));
  for (int i = 0; i < n; i++) {
    int l, r; cin >> l >> r;
    A[l] = min(A[l], r);
  }

  int mi = Mxn;
  for (int i = Mxn; i >= 1; i--) {
    mi = min(A[i], mi);
    ST[0][i] = mi;
    for (int j = 1; j <= LOGN; j++) {
      ST[j][i] = ST[j - 1][ST[j - 1][i]];
    }
  }

  while (q--) {
    int l, r, ans = 0; cin >> l >> r;

    for (int i = LOGN; i >= 0; i--) {
      if (ST[i][l] > r) continue;
      ans += 1<<i; l = ST[i][l];
    }
    cout << ans << '\n';
  }
}

