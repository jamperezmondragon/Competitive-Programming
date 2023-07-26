#include <bits/stdc++.h>
using namespace std;
int const Mxn = 1<<18; 
int const INF = 1e9;

int A[Mxn];
 
struct segementri {
  vector<pair<int, int>> segs;
  void init() {segs.assign(Mxn<<1, {INF, INF});};
  void upd(int i, int val) {
    segs[i += Mxn] = {val, i};
    for (i /= 2; i; i /= 2) {
      segs[i] = min(segs[2*i], segs[2*i + 1]);
    }
  }
  pair<int, int> query(int l, int r) {
    pair<int, int> ans = {INF, INF};
    for (l += Mxn, r += Mxn + 1; l < r; l /= 2, r /= 2) {
      if (l&1) ans = min(ans, segs[l++]);
      if (r&1) ans = min(ans, segs[--r]);
    }
    return ans;
  }
} segtree;
 
int find_diameter(int l, int r) {
  if (l > r) return 0;
  if (l == r) return A[l];
  if (l + 1 == r) return min(A[l], A[l + 1]);
  pair<int, int> X = segtree.query(l, r);
  int x, mid; tie(x, mid) = X;
  int a = find_diameter(l, mid - 1), b = find_diameter(mid + 1, r);
  a = min(2*x, a); b = min(2*x, b);
  return max(a, b);
}
 
 
int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  int tt; 
  for (cin >> tt; tt; tt--) {
    int n, k; cin >> n >> k;
    if (k == n) {
      cout << INF << endl; continue;
    }
    vector<int> a(n);
    for (auto &e : a) cin >> e;
    sort(a.begin(), a.end());
    int x = 0, y = 2*a[k - 1];
    while (x < n - 1 && a[x + 1] <= 2*a[k]) x++;
    x = a[x]; 
    cout << max(x, y) << endl;
  }
}
