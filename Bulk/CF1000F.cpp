#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
const int Mxn = 5e5 + 1;

struct segementri {
  vector<pii> segs;
  segementri() {segs.assign(Mxn<<1, {Mxn + 1, -1});}
  void upd(int i, int x, bool b = false) {
    i += Mxn;
    segs[i] = {x, i - Mxn};
    if (b) segs[i] = {Mxn + 1, -1};
    for (i >>= 1; i; i >>= 1) {
      segs[i] = min(segs[i<<1], segs[i<<1|1]);
    }
  }
  pii query(int l, int r, pii ans = {Mxn + 1, -1}) {
    for (l += Mxn, r += Mxn + 1; l < r; l >>= 1, r >>= 1) {
      if (l&1) ans = min(segs[l++], ans);
      if (r&1) ans = min(segs[--r], ans);
    }
    return ans;
  }
};

int A[Mxn], last[Mxn], prv[Mxn], Ans[Mxn];

struct query {
  int l, r, idx;
  bool operator<(const query & X) {return r < X.r;}
};

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);

  int n, q; cin >> n; 
  memset(last, -1, sizeof(last));
  for (int i = 0; i < n; i++) {
    cin >> A[i]; prv[i] = last[A[i]];
    last[A[i]] = i;
  }

  cin >> q; vector<query> Q(q);
  for (int i = 0; i < q; i++) {
    auto &[l, r, idx] = Q[i];
    cin >> l >> r; idx = i;
    l--, r--;
  }
  sort(Q.begin(), Q.end());
  memset(last, -1, sizeof(last));
  segementri segtree;

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (last[A[i]] != -1) segtree.upd(last[A[i]], Mxn + 1, true);
    segtree.upd(i, last[A[i]]);
    last[A[i]] = i;

    while (cnt < q && Q[cnt].r == i) {
      auto [l, r, idx] = Q[cnt];
      pii X = segtree.query(l, r);
      if (X.first < l) Ans[idx] = A[X.second];
      else Ans[idx] = 0;
      cnt++;
    }

  }
  for (int i = 0; i < q; i++) {
    cout << Ans[i] << '\n';
  }
}
