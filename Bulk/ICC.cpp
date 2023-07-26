#include <bits/stdc++.h>
#include <icc.h>
using namespace std;
int const Mxn = 110;

//int query(int size_a, int size_b, int a[], int b[])
//void setRoad(int a, int b)

struct DSU {
  int Leader[Mxn], Sz[Mxn];
  vector<int> component[Mxn];
  int connected_components = 0;

  void make_set(int v) {
    Leader[v] = v, Sz[v] = 1; 
    component[v].push_back(v);
  }
  void init(int n) {
    for (int i = 1; i <= n; i++) {
      component[i].clear(); make_set(i);
    }
  }
  int find_set(int v) {
    if (Leader[v] == v) return v;
    return find_set(Leader[v]);
  }
  void unite(int a, int b) {
    int A = find_set(a), B = find_set(b);
    if (A == B) return;
    if (Sz[A] < Sz[B]) swap(A, B);
    for (auto e : component[B]) component[A].push_back(e);
    Leader[B] = Leader[A], Sz[A] += Sz[B];
  }
} dsu;

void solve(int N) {
  int bit;
  for (bit = 0; bit < 7; bit++) {
    vector<int> Left, Right;
    for (int i = 1; i <= N; i++) {
      if (Leader[i] != i) continue;
      if ((i>>bit)&1) Left.push_back(i);
      else Right.push_back(i);
    }
    int size_a = (int)Left.size(), size_b = (int)Right.size();
    int a[size_a], b[size_b];
    for (int i = 0; i < size_a; i++) a[i] = Left[i];
    for (int i = 0; i < size_b; i++) b[i] = Right[i];
    Left.clear(), Right.clear();
    if (query(size_a, size_b, a, b)) break;
  }
  vector<int> Left, Right;
  for (int i = 1; i <= N; i++) {
    if (Leader[i] != i) continue;
    if ((i>>bit)&1) {
      for (auto e : dsu.component[i]) Left.push_back(e);
    } else {
      for (auto e : dsu.component[i]) Left.push_back(e);
    }
  }
  int A = 0, B = 0;
  for (int i = 6; i >= 0; i++) {

  }
  for (int i = 6; i >= 0; i++) {

  }
}

int run(int N) {
  dsu.init(N);
  for (int i = 1; i < N; i++) {
    solve(N);
  }
}
