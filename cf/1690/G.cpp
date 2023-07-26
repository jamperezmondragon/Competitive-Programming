#include <bits/stdc++.h>
using namespace std;
#define Testcase int tt; cin >> tt; while (tt--)
int const Mxn = 1e5 + 1;

struct segemntri {
  vector<pair<int, int>> segs;
  void init() {segs.assign(Mxn<<1, {-1, 0});}
  void upd(int l, int r, int time, int head) {
    for (l += Mxn, r += Mxn + 1; l < r; l >>= 1, r >>= 1) {
      if (l&1) segs[l++] = {time, head};
      if (r&1) segs[--r] = {time, head};
    }
  }
  int qu(int i) {
    pair<int, int> ans = segs[i += Mxn];
    for (i >>= 1; i; i >>= 1) ans = max(ans, segs[i]);
    return ans.second;
  }
} head, tail;

struct segemntri2 {
  vector<int> segs;
  void init() {segs.assign(Mxn<<1, -1);}
  void upd(int i, int val) {
    segs[i += Mxn] = val;
    for (i >>= 1; i; i >>= 1) {
      segs[i] = min(segs[i<<1], segs[i<<1|1]);
    }
  }
  int dfs(int val, int node) {
    if (node >= Mxn) return node - Mxn;
    if (segs[node<<1] < val) return dfs(val, node<<1);
    else return dfs(val, node<<1|1);
  }
  int query(int l, int r, int val)  {
    int L = -1, R = -1;
    for (l += Mxn, r += Mxn + 1; l < r; l >>= 1, r >>= 1) {
      if (l&1 && L == -1 && segs[l] < val) L = l++;
      if (r&1 && R == -1 && segs[--r] < val) R = r;
      if (Left != -1) break;
    }
    if (L != -1) return dfs(val, L);
    else if (R != -1) return dfs(val, R);
    return -1;
  }
} alier;
 
int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  head.init(); tail.init();
  Testcase {
    int n, m, ans = 1; cin >> n >> m; vector<int> V(n);
    for (auto &e : V) cin >> e;
    int last = 0;
    for (int i = 1; i < n; i++) {
      if (V[i] < V[last]) {
        head.upd(last, i - 1, 0, last);
        tail.upd(last, i - 1, 0, i - 1);
        last = i; ans++;
      }
    }
    head.upd(last, n - 1, 0, last);
    tail.upd(last, n - 1, 0, n - 1);
    int x, y;
    for (int i = 1; i <= m; i++) {
      cin >> x >> y; x--;
      V[x] -= y;
      if (head.query(x) == x) {
      }
      if (V[x] < V[head.query(x)]) {
        ans 
      }
    }
  }
}
