#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

ll f(ll x) {return x*(x + 1)/2;}
struct Tnode {
  Tnode * ch[2];
  ll l, r, len,  sum, lz, poly;
  Tnode(int L, int R, vector<int> & V) {
    l = L, r = R; len = r - l + 1; sum = 0, lz = 0, poly = 0; ch[0] = NULL, ch[1] = NULL;
    if (L == R) {
      sum = V[L]; return;
    }
    ll Mid = (L + R)>>1;
    ch[0] = new Tnode(L, Mid, V); ch[1] = new Tnode(Mid + 1, R, V);
    sum = ch[0]->sum + ch[1]->sum;
  }
  void propagate() {
    if (l == r) return;
    ch[0]->sum += lz*ch[0]->len;
    ch[1]->sum += lz*ch[1]->len;
    if (poly) {
      ch[1]->sum += poly*ch[0]->len*ch[1]->len;
      ch[1]->lz += poly*ch[0]->len;

      ch[1]->sum += poly*f(ch[1]->len);
      ch[0]->sum += poly*f(ch[0]->len);
    }
    ch[0]->lz += lz; ch[1]->lz += lz;
    ch[0]->poly += poly; ch[1]->poly += poly;
    lz = 0; poly = 0; 
  }
  ll query(int L, int R) {
    if (r < L || R < l) return 0;
    if (L <= l && r <= R) return sum;
    propagate();
    ll val = ch[0]->query(L, R) + ch[1]->query(L, R);
    sum = ch[0]->sum + ch[1]->sum;
    return val;
  }
  void upd_poly(int L, int R) {
    if (r < L || R < l) return;
    if (L <= l && r <= R) {
      poly++; lz += (l - L); 
      sum += f(len) + (l - L)*len;
      return;
    }
    propagate();
    ch[0]->upd_poly(L, R); ch[1]->upd_poly(L, R);
    sum = ch[0]->sum + ch[1]->sum;
  }
};

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, q; cin >> n >> q;
  vector<int> V(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> V[i];
  }
  Tnode SegTree(1, n, V);
  cout << endl;
  while (q--) {
    int x, a, b; cin >> x >> a >> b;
    if (x - 1) {
      cout << SegTree.query(a, b) << endl;
    } else {
      SegTree.upd_poly(a, b);
    }
  }
}
