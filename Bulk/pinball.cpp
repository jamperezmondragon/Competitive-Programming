#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int Mxn = 3e5 + 3;
const ll INF = 1e17;

struct SegTree {
  vector<ll> segs;
  SegTree() {segs.assign(Mxn<<1, INF);}
  void upd(int i, ll x) {
    i += Mxn; segs[i] = min(segs[i], x);
    for (i >>= 1; i; i >>= 1) {
      segs[i] = min(segs[i<<1], segs[i<<1|1]);
    }
  }
  ll query(int l, int r, ll ans = INF) {
    for (l += Mxn, r += Mxn + 1; l < r; l >>= 1, r >>= 1) {
      if (l&1) ans = min(ans, segs[l++]);
      if (r&1) ans = min(ans, segs[--r]);
    }
    return ans;
  }
} St[2];

struct coso {int a, b, c; ll d;};
ll dp[2][Mxn];

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int m, n, cnt = 0; cin >> m >> n;
  vector<coso> A(m);
  map<int, int> cc; cc[1], cc[n];
  for (auto &[a, b, c, d] : A) {
    cin >> a >> b >> c >> d;
    cc[a], cc[b], cc[c]; 
  }
  for (auto &[x, y] : cc) y = cnt++;
  for (auto &[a, b, c, d] : A) {
    a = cc[a], b = cc[b], c = cc[c]; 
  }
  n = cc[n];
  St[0].upd(0, 0); St[1].upd(n, 0);
  for (int i = 0; i < m; i++) {
    auto [a, b, c, d] = A[i];
    for (int j = 0; j < 2; j++) {
      dp[j][i] = St[j].query(a, b);
      if (dp[j][i] == INF) continue;
      dp[j][i] += d;
      St[j].upd(c, dp[j][i]);
    }
  }
  ll ans = INF; bool flag = false;
  for (int i = 0; i < m; i++) {
    if (dp[0][i] != INF && dp[1][i] != INF) flag = true;
    ans = min(dp[0][i] + dp[1][i] - A[i].d, ans);
  }
  if (flag) cout << ans << '\n';
  else cout << -1 << '\n';
}


