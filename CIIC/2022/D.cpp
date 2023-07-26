#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const Mxn = 1<<18;
int n, q, tt, x, y, z;
int off[4] = {1, };
struct instruccion {
  ll delta[4];
  int mirando;
  instruccion() { // identity element
    for (int i = 0; i < 4; i++) delta[i] = 0;
    mirando = 0;
  }
  void print() {
    cout << (delta[0] - delta[2]) << " ";
    cout << (delta[3] - delta[1]) << " ";
    cout << mirando << endl;
  }
};

instruccion merge(instruccion A, instruccion B) {
  instruccion res;
  for (int i = 0; i < 4; i++) {
    res.delta[i] = A.delta[i] + B.delta[(i + A.mirando)%4];
  }
  res.mirando = (A.mirando + B.mirando)%4;
  return res;
}


instruccion segs[Mxn<<1];

void build_segtree() {
  for (int i = Mxn - 1; i > 0; i--) {
    segs[i] = merge(segs[2*i], segs[2*i + 1]);
  }
}

void update(int i, instruccion A) {
  segs[i += Mxn] = A;
  for (i /= 2; i; i /= 2) {
    segs[i] = merge(segs[2*i], segs[2*i + 1]);
  }
}

instruccion query(int l, int r) {
  instruccion lans, rans;
  for (l += Mxn, r += Mxn + 1; l < r; l /= 2, r /= 2) {
    if (l&1) lans = merge(lans, segs[l++]);
    if (r&1) rans = merge(segs[--r], rans);
  }
  return merge(lans, rans);
}

int main() {
  std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = Mxn; i < Mxn + n; i++) {
    cin >> x >> y;
    instruccion C;
    if (x - 1) C.mirando = y;
    else C.delta[0] = y;
    segs[i] = C;
  }
  build_segtree();
  cin >> q;
  while (q--) {
    cin >> tt;
    if (tt - 1) {
      cin >> x >> y >> z;
      instruccion aux;
      if (y - 1) aux.mirando = z;
      else aux.delta[0] = z;
      update(x, aux);
    } else {
      cin >> x >> y;
      query(x, y).print();
    }
  }
}
