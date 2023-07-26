#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

struct Node {
  Node * ch[2];
  int l, r; ll len, sum, lz, set;
  Node(int L, int R, vector<int> & V) {
    l = L, r = R; len = r - l + 1; lz = 0; set = 0;
    if (L == R) {
      sum = V[L]; return;
    }
    int Mid = (L + R)>>1;
    ch[0] = new Node(L, Mid, V); ch[1] = new Node(Mid + 1, R, V);
    sum = ch[0]->sum + ch[1]->sum;
  }
  void propagate() {
    if (set) {
      ch[0]->sum = ch[0]->len*set;
      ch[1]->sum = ch[1]->len*set;
      ch[0]->set = set; ch[1]->set = set;
      ch[0]->lz = 0; ch[1]->lz = 0;
      set = 0;
    }
    ch[0]->sum += lz*ch[0]->len;
    ch[1]->sum += lz*ch[1]->len;
    ch[0]->lz += lz; ch[1]->lz += lz;
    lz = 0;
  }
  void sum_upd(int L, int R, ll x) {
    if (R < l || r < L) return;
    if (L <= l && r <= R) {
      sum += len*x; lz += x; 
      return;
    }
    propagate();
    ch[0]->sum_upd(L, R, x); ch[1]->sum_upd(L, R, x);
    sum = ch[0]->sum + ch[1]->sum;
  }
  void set_upd(int L, int R, ll x) {
    if (R < l || r < L) return;
    if (L <= l && r <= R) {
      sum = len*x; lz = 0; set = x;
      return;
    }
    propagate();
    ch[0]->set_upd(L, R, x); ch[1]->set_upd(L, R, x);
    sum = ch[0]->sum + ch[1]->sum;
  }
  ll query(int L, int R) {
    if (R < l || r < L) return 0;
    if (L <= l && r <= R) return sum;
    propagate();
    ll aux = ch[0]->query(L, R) + ch[1]->query(L, R);
    sum = ch[0]->sum + ch[1]->sum;
    return aux;
  }
};

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n, q; cin >> n >> q; vector<int> V(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> V[i];
  }
  Node SegTree(1, n, V);
  int t, a, b; ll x;
  while (q--) {
    cin >> t;
    if (t == 1) {
      cin >> a >> b >> x;
      SegTree.sum_upd(a, b, x);
    } else if (t == 2) {
      cin >> a >> b >> x;
      SegTree.set_upd(a, b, x);
    } else {
      cin >> a >> b;
      cout << SegTree.query(a, b) << endl;
    }
  }
}
