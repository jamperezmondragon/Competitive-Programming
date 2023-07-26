#include <bits/stdc++.h>
using namespace std;
int const Mxn = 1024;
int n, q, x, y, z; 


struct fenwi {
  vector<int> BIT;
  void init () { BIT.assign(Mxn, 0); }

  void add(int i, int val) {
    for (; i < Mxn; i += i&(-i)) BIT[i] += val;
  }
  int sum(int i, int val = 0) {
    for (; i > 0; i -= i&(-i)) val += BIT[i];
    return val;
  }
} bit;

struct Intervalos_thingy {
  map<int, int> mp;
  int query(int i) {
    auto it = mp.lower_bound(i); it--;
    return it->second;
  }
  upd(int l, int r) {

  }
} thingy;

int main() {
  cin.tie(0), ios_base::sync_with_stdio(0);
  cin >> n >> q;
  for (int i = 1; i <= q; i++) {
    cin >> x >> y >> z;
    if (x == 2) {
      event T; T.inv = true, T.change = 0, T.time = i;
      Insert(y, z, T);
    } else {
      event T; T.inv = false, T.change = x, T.time = i;
      Insert(y, z, T);
    }
  }
  A = {0, 0}; bit.init();
  dfs(1);
  int a = 0;
  for (int i = 1; i <= n; i++) {
    a += ans[i];
  }
  cout << a << " " << n - a << endl;
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
}
