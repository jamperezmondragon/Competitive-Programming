#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const Mxn = 1<<18;
int n, q, x, y, z; 

struct segementri {
  vector<ll> segs;
  segementri() { segs.assign(Mxn<<1, INT_MAX);}
  void upd(int i, int val) {
    segs[i += Mxn] = val;
    for (i /= 2; i; i /= 2) segs[i] = min(segs[2*i], segs[2*i + 1]);
  }
  ll query(int l, int r, ll ans = INT_MAX) {
    for (l += Mxn, r += Mxn + 1; l < r; l /= 2, r /= 2) {
      if (l&1) ans = min(segs[l++], ans);
      if (r&1) ans = min(segs[--r], ans);
    }
    return ans;
  }
};
segementri ST[2];



int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> x; 
    ST[0].upd(i, x - i);
    ST[1].upd(i, x + i);
  }
  while (q--) {
    cin >> x;
    if (x - 1) {
      cin >> y;
      cout << min(ST[0].query(0, y) + y, ST[1].query(y, Mxn - 1) - y) << "\n";
    } else {
      cin >> y >> z;
      ST[0].upd(y, z - y);
      ST[1].upd(y, z + y);
    }
  }
}
