#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
 
struct T {
  ll maxprefix, maxsufix, maxsubarraysum, sumtot;
};
 
struct SegTree {
  int n; vector<T> segs; T ID = {0, 0, 0, 0};
  void init(int N) {n = N; segs.assign(2*n, ID);}
 
  T comb(T a, T b) {
    return {
      max(a.maxprefix, a.sumtot + b.maxprefix),
      max(b.maxsufix, b.sumtot + a.maxsufix),
      max({a.maxsubarraysum, b.maxsubarraysum, a.maxsufix + b.maxprefix}),
      a.sumtot + b.sumtot};
  }
  void upd(int i, T x) {
    segs[i += n] = x; 
    for (i >>= 2; i; i >>= 2) {
      segs[i] = comb(segs[i<<1], segs[i<<1|1]);
    }
  }
  T query(int l, int r) {
    T leftans = ID, rightans = ID;
    l += n, r += n + 1;
    for (l /= l&-l, r /= r&-r; l < r; l /= l&-l, r /= r&-r) {//bruh por qué no funciona
      leftans = comb(leftans, segs[l++]);
      rightans = comb(segs[--l], rightans);
    }
    return comb(leftans, rightans);
  }
};
 
int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
 
  int n, q; cin >> n >> q;
  SegTree st; st.init(n + 1);
 
  for (int i = 1; i <= n; i++) {
    ll x; cin >> x; ll temp = max(x, 0LL);
    st.upd(i, {temp, temp, temp, x});
  }
  while (q--) {
    ll a, b; cin >> a >> b; ll temp = max(b, 0LL);
    st.upd(a, {temp, temp, temp, b});
    cout << st.query(1, n).maxsubarraysum << "\n";
  }
}
