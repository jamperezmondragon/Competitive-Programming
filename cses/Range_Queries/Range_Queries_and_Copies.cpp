#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
 
#define GU getchar_unlocked()
#define PU putchar_unlocked
 
int in() {
    int re = 0;
    char c = GU;
    while (c == ' ' || c == '\n')
        c = GU;
    while (c >= '0' && c <= '9')
        re = (re << 3) + (re << 1) + c - '0', c = GU;
    return re;
}
 
void out(ll x) {
    char str[20];
    int pos = 0;
    do {
        str[pos++] = x % 10 + '0';
        x /= 10;
    } while (x);
    for (int i = pos - 1; i >= 0; i--)
        PU (str[i]);
    PU ('\n');
}
int const Mxn = 2e5 + 10;
int n, q, x, y, z, w, curr_size = 1, num_queries = 0;

//persistencia who?
 
struct fenwi {
  ll BIT[Mxn];
  void upd(int i, ll val)  {
    for (; i < Mxn; i += i&(-i)) BIT[i] += val;
  }
  ll sum(int i, ll val = 0) {
    for (; i > 0; i -= i&(-i)) val += BIT[i];
    return val;
  }
} bit;
struct eventos {
  int tipo;
  //if tipo == 1 - update in current tree
  int idx, val;
  //if tipo == 2 - query in current tree;
  int L, R, I;
  //if tipo == 3 - create a copy, ie dfs into child.
  int child;
};
vector<eventos> Tree[Mxn];
ll Ans[Mxn];
 
void dfs(int node) {
  vector<pair<int, int>> reset;
  for(auto X : Tree[node]) {
    if (X.tipo == 1) {
      ll aux = bit.sum(X.idx) - bit.sum(X.idx - 1);
      bit.upd(X.idx, X.val - aux);
      reset.push_back({X.idx, X.val - aux});
      continue;
    }
    if (X.tipo == 2) {
      Ans[X.I] = bit.sum(X.R) - bit.sum(X.L - 1);
      continue;
    }
    if (X.tipo == 3) {
      dfs(X.child);
    }
  }
  for (auto [a, b] : reset) bit.upd(a, -b);
}
 
int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);

  n = in(), q = in();
  for (int i = 1; i <= n; i++) {
    x = in(); bit.upd(i, x);
  }
  for (int i = 0; i < q; i++) {
    x = in();
    eventos aux; aux.tipo = x;
    if (x == 1) {
      y = in(), z = in(), w = in();
      aux.idx = z; aux.val = w;
      Tree[y].push_back(aux);
      continue;
    }
    if (x == 2) {
      y = in(), z = in(), w = in();
      aux.L = z, aux.R = w, aux.I = num_queries++;
      Tree[y].push_back(aux);
      continue;
    }
    if (x == 3) {
      y = in();
      aux.child = ++curr_size;
      Tree[y].push_back(aux);
    }
  }
  dfs(1);
  for (int i = 0; i < num_queries; i++) {
    out(Ans[i]);
  }
}
