#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)a.size()
int const Mxn = 4101;

int lobo[26] = {0, -1, 1, -1, -1, -1, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 3, -1, -1, -1, -1, -1};
struct relsB {
  uint_fast64_t B[4][Mxn/64 + 1];
  void init(string & s) {
    for (int i = 0; i < sz(s); i++) {
      B[lobo[s[i] - 'A']][i/64] ^= 1LL<<(i%64);
    }
  }
} A[Mxn];
int grid[Mxn][Mxn], is_good[Mxn];

int count(relsB X, relsB Y, int ans = 0) {
  for (int i = 0; i <= Mxn/64; i++) {
    for (int j = 0; j < 4; j++) {
      ans += __builtin_popcount((X.B[j][i])^(Y.B[j][i]));
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, k, m; cin >> n >> m >> k;
  k <<= 1; string s;
  for (int i = 0; i < n; i++) {
    cin >> s; A[i].init(s);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      grid[i][j] = count(A[i], A[j]);
      if (grid[i][j] != k) break;
    }
  }
  for (int i = 0; i < n; i++) {
    is_good[i] = 1;
    for (int j = 0; j < n; j++) {
      if (j == i) continue;
      is_good[i] &= (grid[i][j] == k);
    }
  }
  for (int i = 0; i < n; i++) {
    if (!is_good[i]) continue;
    cout << i + 1 << endl; break;
  }
}
