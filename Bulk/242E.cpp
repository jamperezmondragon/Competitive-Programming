#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
const int LOGN = 20;  

struct Tnode {
  int sum, l, r, len, lz;
  Tnode * ch[2];
  void print() {cout << "[" <<  l << ", " << r << "] : sum: " << sum << ". lz: " << lz << endl;}
  void merge() {sum = ch[0]->sum + ch[1]->sum;}
  void propagate() {
    if (!lz) return;
    ch[0]->sum = ch[0]->len - ch[0]->sum;
    ch[1]->sum = ch[1]->len - ch[1]->sum;
    ch[0]->lz ^= 1;
    ch[1]->lz ^= 1;
    lz ^= 1;
  }
  Tnode(int L, int R, vector<int> & V) {
    sum = 0; l = L, r = R; len = R - L + 1; lz = 0;
    if (L == R) {
      sum = V[L]; return;
    }
    int Mid = (L + R)>>1;
    ch[0] = new Tnode(L, Mid, V); ch[1] = new Tnode(Mid + 1, R, V);
    merge();
  }
  void upd(int L, int R) {
    if (R < l || r < L) return;
    if (L <= l && r <= R) {
      sum = len - sum; lz ^= 1; return;
    }
    propagate();
    ch[0]->upd(L, R); ch[1]->upd(L, R);
    merge();
  }
  int query(int L, int R) {
    if (R < l || r < L) return 0;
    if (L <= l && r <= R) return sum;
    propagate();
    int ans = ch[0]->query(L, R) + ch[1]->query(L, R);
    merge();
    return ans;
  }
};

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n; 
  vector<vector<int>> V(LOGN + 1, vector<int>(n + 1));
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    for (int j = 0; j <= LOGN; j++) V[j][i] = ((x>>j)&1);
  }
  vector<Tnode> T;
  for (int i = 0; i <= LOGN; i++) {
    Tnode X(1, n, V[i]); T.push_back(X);
  }
  int q; cin >> q;
  while (q--) {
    int t, l, r, x;
    cin >> t;
    if (t == 1) {
      cin >> l >> r;
      ll ans = 0;
      for (int i = 0; i <= LOGN; i++) {
        ans += (1LL<<i)*(1LL)*T[i].query(l, r);
      }
      cout << ans << endl;
    }
    if (t == 2) { 
      cin >> l >> r >> x;
      for (int i = 0; i <= LOGN; i++) {
        if ((x>>i)&1) T[i].upd(l, r);
      }
    }
  }
}
