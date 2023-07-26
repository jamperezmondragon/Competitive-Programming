#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using vi = vector<int>;
#define sz(a) (int)a.size()
ll const LOGN = 31;
ll const Mxn = 1e5 + 1;
ll const offset = 1e9 + 10;

struct line {
  ll a, b;
  ll operator()(ll x) {return a*(x - offset) + b + offset;}
} rectas[Mxn];
struct Node { //Li Chao Trie
  Node * ch[2];
  line A;
  Node() {ch[0] = NULL, ch[1] = NULL, A.a = 0, A.b = 0;}
  bool exists(int x) {return ch[x] != NULL;}
  void Insert(line L, ll v = 0, ll i = LOGN) {
    if (i == 0 || A.a == L.a) {
      if (A(v + (1LL<<i)) < L(v + (1LL<<i))) swap(A, L);
      return;
    } 
    if (A.a > L.a) swap(A, L);
    if (A(v + (1LL<<i)) < L(v + (1LL<<i))) {
      swap(A, L);
      if (!exists(0)) ch[0] = new Node;
      ch[0]->Insert(L, v, i-1);
    } else {
      if (!exists(1)) ch[1] = new Node;
      ch[1]->Insert(L, v + (1LL<<i), i - 1);
    }
  }
  ll query(ll x, int i = LOGN) {
    if (i == 0 || !exists((x>>i)&1)) return A(x);
    return max(A(x), ch[(x>>i)&1]->query(x, i-1));
  }
}; 

struct query {
  ll x, y; int idx;
};
vi Ans[Mxn];
Node * cesar[LOGN];

void search(int L, int R, vector<query> & V, int d = 0) { //parelel binary search
  if (L + 1 == R) {
    for (auto [x, y, idx] : V) if (rectas[L](x) > y) Ans[L].push_back(idx);
    return;
  }
  int mid = (L + R)>>1;
  vector<query> Left, Right;

  for (int i = L; i < mid; i++) cesar[d]->Insert(rectas[i]);
  for (auto X : V) {
    if (X.y >= cesar[d]->query(X.x)) Right.push_back(X);
    else Left.push_back(X);
  }
  search(L, mid, Left, d + 1); search(mid, R, Right, d + 1);
}

int main() {
  int n; cin >> n;
  vector<query> V;
  for (int i = 1; i <= n; i++) {
    ll x, y; cin >> x >> y;
    x += offset, y += offset;
    V.push_back({x, y, i});
  }
  int m; cin >> m;
  for (int i = 0; i < m; i++) cin >> rectas[i].a >> rectas[i].b;
  for (int i = 0; i < LOGN; i++) cesar[i] = new Node;
  search(0, m, V);
  for (int i = 0; i < m; i++) {
    cout << sz(Ans[i]) << " ";
    for (auto e : Ans[i]) cout << e << " ";
    cout << '\n';
  }
}

