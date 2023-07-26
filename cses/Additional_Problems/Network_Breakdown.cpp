#include <bits/stdc++.h>
using namespace std;
const int Mxn = 2e5 + 1;

struct DSU {
  vector<int> leader, Sz;
  int cnt;
  DSU(int n) {
    leader.resize(n + 1); Sz.assign(n + 1, 1);
    cnt = n; iota(leader.begin(), leader.end(), 0);
  }
  int find(int x) {return (leader[x] == x) ? x : (leader[x] = find(leader[x]));}
  int unite(int a, int b) {
    int A = find(a), B = find(b);
    if (A == B) return 0;
    if (Sz[A] < Sz[B]) swap(A, B);
    Sz[A] += Sz[B]; leader[B] = A;
  }
};

struct Edge {
  int a, b, v;
  bool operator<(const & Edge A) const {return v > A.v;}
};

int main() {
  int n, m, k; cin >> n >> m >> k;
  for (int i = 0; )
}
