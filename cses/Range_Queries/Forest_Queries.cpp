#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int psum[1005][1005]; int n, q; cin >> n >> q;
  memset(psum, 0, sizeof(psum));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      char x; cin >> x;
      psum[i][j] = psum[i - 1][j] + psum[i][j - 1]
        - psum[i - 1][j - 1] + (x == '*');
    }
  }
  while (q--) {
    int x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
    cout << psum[x2][y2] 
      - psum[x1 - 1][y2]
      - psum[x2][y1 - 1] 
      + psum[x1 - 1][y1 - 1] << endl;
  }
}
