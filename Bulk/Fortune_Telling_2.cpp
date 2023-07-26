#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long int;
#define all(a) a.begin(), a.end()
const int Mxn = 6e5 + 2;

struct segtree_sum {
  vector<int> segs;
  segtree_sum() {segs.assign(Mxn<<1, 0);}
  void upd(int i, int x) {
    i += Mxn; segs[i] += x;
    for (i >>= 1; i; i >>= 1) {
      segs[i] = segs[i<<1] + segs[i<<1|1];
    }
  }
  int query(int l, int r, int ans = 0) {
    for (l += Mxn, r += Mxn + 1; l < r; l >>= 1, r >>= 1) {
      if (l&1) ans += segs[l++];
      if (r&1) ans += segs[--r];
    }
    return ans;
  }
};

struct segtree_max {
  vector<int> segs;
  segtree_max() {segs.assign(Mxn<<1, -1);}
  void upd(int i, int x) {
    i += Mxn; segs[i] = x;
    for (i >>= 1; i; i >>= 1) {
      segs[i] = max(segs[i<<1], segs[i<<1|1]);
    }
  }
  int query(int l, int r, int ans = -1) {
    for (l += Mxn, r += Mxn + 1; l < r; l >>= 1, r >>= 1) {
      if (l&1) ans = max(segs[l++], ans);
      if (r&1) ans = max(segs[--r], ans);
    }
    return ans;
  }
};

struct cuchao {
  int idx, sufix, val;
  bool operator<(const cuchao & X) {return sufix > X.sufix;}
};

//stress test brute force
ll brute_force(int n, int k, vector<pii> A, vector<int> B, ll ans = 0, ll idx = 0) {
  ll card[2][n], oper[k];
  for (int i = 0; i < n; i++) card[0][i] = A[i].first, card[1][i] = A[i].second;
  for (int i = 0; i < k; i++) oper[i] = B[i];
  for (int i = 0; i < n; i++, idx = 0) {
    for (int j = 0; j < k; j++) {
      idx ^= (card[idx][i] <= oper[j]);
    }
    ans += card[idx][i];
  }
  return ans;
}

ll my_sol(int n, int k, vector<pii> A, vector<int> T) {

  ll ans = 0, cnt = 0;
  map<ll,ll> cc;
  map<ll, ll> anti;
  for (auto [x, y] : A) cc[x], cc[y];
  for (auto e : T) cc[e];
  for (auto &[x, y] : cc) y = cnt++;
  for (auto &[x, y] : A) x = cc[x], y = cc[y];
  for (auto &e : T) e = cc[e];
  for (auto [x, y] : cc) anti[y] = x;
 
  segtree_max St_max;
  vector<cuchao> Count(n);
  for (int i = 0; i < k; i++) {
    St_max.upd(T[i], i);
  }
  for (int i = 0; i < n; i++) {
    auto &[idx, sufix, val] = Count[i];
    idx = i;
    auto [l, r] = A[i];
    if (l > r) {
      sufix = St_max.query(r, l - 1);
      val = l;
    } else {
      sufix = St_max.query(l, r - 1);
      val = r;
    }
  }
  sort(all(Count));
  segtree_sum St_sum; vector<int> Ans(n);
  for (int i = k - 1; i >= 0; i--) {
    while (cnt < n && Count[cnt].sufix == i) {
      auto &[idx, sufix, val] = Count[cnt++];
      Ans[idx] = St_sum.query(val, Mxn - 1);
    }
    St_sum.upd(T[i], 1);
  }
  for (int i = 0; i < n; i++) {
    auto [l, r] = A[i];
    if (l > r) {
      swap(l, r);
      if (St_max.query(l, r - 1) == -1) {
        if (St_sum.query(r, Mxn - 1)&1) ans += anti[l];
        else ans += anti[r];
      } else {
        if (Ans[i]&1) ans += anti[l];
        else ans += anti[r];
      }
    } else {
      if (St_max.query(l, r - 1) == -1) {
        if (St_sum.query(r, Mxn - 1)&1) ans += anti[r];
        else ans += anti[l];
      } else {
        if (Ans[i]&1) ans += anti[l];
        else ans += anti[r];
      }
    }
  }
  return ans;
}

int main() {
  //freopen("/fortune_telling2-data/01-03.in", "r", stdin);
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tt; cin >> tt;
  while (tt--) {
    cout << tt << endl;
    int n = rand()%10;
    int k = rand()%10;
    vector<pii> A(n); vector<int> B(k);
    for (auto &[x, y] : A) x = rand()%10, y = rand()%10;
    for (auto &e : B) e = rand()%10;
    if (my_sol(n, k, A, B) != brute_force(n, k, A, B)) {
      cout << "epale\n la bruta dice:" << brute_force(n, k, A, B) << "\n Y tu sol dice: " << my_sol(n, k, A, B) << "\n en este caso: \n";
      cout << n << " " << k << endl;
      for (auto [x, y] : A) cout << x << " " << y << '\n';
      for (auto e : B) cout << e << '\n';
    }
  }
}
