#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const offset = 1e6 + 1;
ll const Mxn = 2e6 + 3;

struct SegTree {
  vector<ll> segs;
  SegTree() {segs.assign(Mxn<<1, 0);}
  void upd(int i, ll x) {
    i += Mxn; segs[i] += x;
    for (i >>= 1; i; i >>= 1) {
      segs[i] = segs[i<<1] + segs[i<<1|1];
    }
  }
  ll query(int l, int r, ll ans = 0) {
    for (l += Mxn, r += Mxn + 1; l < r; l >>= 1, r >>= 1) {
      if (l&1) ans += segs[l++];
      if (r&1) ans += segs[--r];
    }
    return ans;
  }
};

struct event {
  bool typo;
  int a, b, v; 
  bool operator<(const event & A) const {return v < A.v;}
};

int x, y, z, w;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n; vector<event> Events;
  for (int i = 0; i < n; i++) {
    cin >> x >> y >> z >> w;
    x += offset; y += offset; 
    z += offset; w += offset; 
    event A, B;
    if (x == z) {
      A.typo = true; A.v = x; A.a = y, A.b = w;
      Events.push_back(A);
    } else {
      A.typo = false; A.v = x; A.a = y; A.b = 1;
      B.typo = false; B.v = z; B.a = y; B.b = -1;
      Events.push_back(A), Events.push_back(B);
    }
  }
  sort(Events.begin(), Events.end());
  SegTree segtree;
  ll ans = 0;
  for (auto [typo, a, b, v] : Events) {
    if (typo) {
      ans += segtree.query(a, b);
    } else {
      segtree.upd(a, b);
    }
  }
  cout << ans << '\n';
}
