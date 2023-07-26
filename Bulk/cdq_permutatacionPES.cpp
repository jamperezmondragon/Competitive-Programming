#include <bits/stdc++.h>
using namespace std;
int const Mxn = 12e4 + 10; 
int n, q, x, y;

struct fenwick {
  int BIT[Mxn];
  void upd(int i, int val) {
    for (; i < Mxn; i += i&(-i)) BIT[i] += val;
  }
  int sum(int i, int ans = 0) {
    for (; i > 0; i -= i&(-i)) ans +=  BIT[i];
    return ans;
  }
} bit;

struct event {
  int idx, val, time, p;
};

vector<event> V;
int ans[Mxn];

//cdq divide and conquer
void solve(int l, int r) {
  if (l + 1 == r) return;
  int m = (l + r)>>1;
  solve(l, m), solve(m, r);
  int i = l, j = m;
  vector<event> tmp;
  vector<pair<int, int>> reset;
  while (i < m && j < r) {
    if (V[i].idx > V[j].idx) {
      ans[V[j].time] += bit.sum(Mxn - 1) - bit.sum(V[j].val);
      tmp.push_back(V[j++]);
    } else {
      bit.upd(V[i].val, V[i].p);
      reset.push_back({V[i].val, V[i].p});
      tmp.push_back(V[i++]);
    }
  }
  while (i < m) {
    tmp.push_back(V[i++]);
  }
  while (j < r) {
    ans[V[j].time] += bit.sum(Mxn - 1) - bit.sum(V[j].val);
    tmp.push_back(V[j++]);
  }
  for (i = l; i < r; i++) V[i] = tmp[i - l];
  for (auto [a, b] : reset) bit.upd(a, -b);
  reset.clear(); tmp.clear();
}

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> n >> q;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i]; V.push_back({i, a[i], 0, 1});
  }
  for (int i = 1; i <= q; i++) {
    cin >> x >> y;
    V.push_back({x, y, i, 1});
    V.push_back({x, a[x], i, -1});
    a[x] = y;
  }
  solve(0, (int)V.size());
  int aux = ans[0];
  for (int i = 1; i <= q; i++) {
    aux += ans[i];
    cout << aux << endl;
  }
}
