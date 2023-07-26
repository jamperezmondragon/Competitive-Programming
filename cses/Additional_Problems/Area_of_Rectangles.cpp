#include <bits/stdc++.h>
using namespace std; 
using ll = long long int;
using pii = pair<int, ll>;
const ll offset = 1e6 + 1;

auto combine(pii A, pii B) -> pii {
  if (A.first == B.first) {
    return {A.first, A.second + B.second};
  } 
  if (A.first < B.first) return A;
  else return B;
}

struct Node {
  Node * ch[2];
  pii A; ll lz, l, r;
  Node(int L, int R) {
    l = L, r = R, lz = 0;
    if (L == R) {
      A = {0, 1}; return;
    }
    int Mid = (L + R)>>1;
    ch[0] = new Node(L, Mid); ch[1] = new Node(Mid + 1, R);
    A = combine(ch[0]->A, ch[1]->A);
  }
  void propagate() {
    ch[0]->A.first += lz;
    ch[1]->A.first += lz;
    ch[0]->lz += lz;
    ch[1]->lz += lz;
    lz = 0;
  }
  void sum_upd(int L, int R, ll x) {
    if (r < L || R < l) return;
    if (L <= l && r <= R) {
      A.first += x; lz += x; return;
    }
    propagate();
    ch[0]->sum_upd(L, R, x); ch[1]->sum_upd(L, R, x);
    A = combine(ch[0]->A, ch[1]->A);
  }
  pii query(int L, int R) {
    if (r < L || R < l) return {offset, 0};
    if (L <= l && r <= R) return A;
    propagate();
    pii aux = combine(ch[0]->query(L, R), ch[1]->query(L, R));
    A = combine(ch[0]->A, ch[1]->A);
    return aux; 
  }
};

struct event {
  ll v, a, b, c; 
  bool operator<(const event & A) const {return v < A.v;}
};

ll n, x, y, z, w;
ll ans = 0;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  vector<event> V;
  for (int i = 0; i < n; i++) {
    cin >> x >> y >> z >> w;
    x += offset; y += offset; 
    z += offset; w += offset;
    V.push_back({x, y, w, 1});
    V.push_back({z, y, w, -1});
  }
  x = 0; Node SegTree(1, 2*offset);
  sort(V.begin(), V.end());
  for (auto [v, a, b, c] : V) {
    //pii aux = SegTree.query(1, 2*offset);
    //cout << aux.first << " " << 2*offset - aux.second << endl;
    //cout << v - offset << " " << a - offset << " " << b - offset << " " << c << endl;
    //cout << (v - x)*(2*offset - SegTree.query(1, 2*offset).second) << endl; 
    
    ans += (v - x)*(2*offset - SegTree.query(1, 2*offset).second);
    SegTree.sum_upd(a, b - 1, c);
    x = v;
  }
  cout << ans << '\n';
}

