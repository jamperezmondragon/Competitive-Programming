#pragma GCC optimize("unroll-loops", "O3")
#pragma GCC target("avx2","popcnt")
#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
const int Mxn = 1e5 + 1;


struct DSU {
  vector<int> leader, Sz;
  DSU(int n) {
    leader.resize(n + 1); Sz.assign(n + 1, 1); iota(all(leader), 0);
  }
  int find(int x) {
    return ((leader[x] == x) ? x : (leader[x] = find(leader[x])));
  }
  void unite(int a, int b) {
    int A = find(a), B = find(b);
    if (A == B) return;
    if (Sz[A] < Sz[B]) swap(A, B);
    Sz[A] += Sz[B]; leader[B] = A;
  }
};
bitset<Mxn> A;

int main()  {
  int n, m, a, b; cin >> n >> m; DSU dsu(n);
  for (int i = 0; i < m; i++) {
    cin >> a >> b; dsu.unite(a, b);
  }
  multiset<int> S; vector<bool> vis(n + 1, false);
  for (int i = 1; i <= n; i++) {
    if (!vis[dsu.find(i)]) {
      S.insert(dsu.Sz[dsu.find(i)]); vis[dsu.find(i)] = true;
    }
  }
  A[0] = 1;
  while (sz(S)) {
    int x = *S.begin(), y = S.count(x);
    if (y&1) {
      A |= A<<x;
      for (int i = 0; i < y/2; i++) S.insert(x<<1);
    } else {
      A |= A<<x; A |= A<<x;
      for (int i = 0; i < y/2 - 1; i++) S.insert(x<<1);
    }
    S.erase(x);
  }
  for (int i = 1; i <= n; i++) cout << A[i];
}
