#include <bits/stdc++.h>
using namespace std;
int const Mxn = 2e5 + 10;
int const LOGN = 23;
int n, m, x, y, cnt = 0;
int SparseTable[Mxn][LOGN + 1], Depth[Mxn], Preorden[Mxn], Postorden[Mxn];
vector<int> adjList[Mxn];
int Difference_Array[2*Mxn];
int psum[2*Mxn];


void Dfs(int node, int parent) {
  SparseTable[node][0] = parent;
  for (int i = 1; i <= LOGN; i++) {
    SparseTable[node][i] = SparseTable[SparseTable[node][i - 1]][i - 1];
  }
  Preorden[node] = ++cnt;
  for (auto child : adjList[node]) {
    if (child == parent) continue;
    Depth[child] = Depth[node] + 1;
    Dfs(child, node);
  }
  Postorden[node] = ++cnt;
}

int Jump(int a, int salto) {
  for (int i = 0; i <= LOGN; i++) {
    if ((salto>>i)&1) a = SparseTable[a][i];
  }
  return a;
}

int LCA(int a, int b) {
  if (Depth[a] < Depth[b]) swap(a, b);
  a = Jump(a, Depth[a] - Depth[b]);
  if (a == b) return a;
  for (int i = LOGN; i >= 0; i--) {
    if (SparseTable[a][i] != SparseTable[b][i]) {
      a = SparseTable[a][i]; b = SparseTable[b][i];
    }
  }
  return SparseTable[a][0];
}

void Process_Paths() {
  cin >> x >> y;
  Difference_Array[Preorden[x]]++;
  Difference_Array[Preorden[y]]++;
  Difference_Array[Preorden[LCA(x, y)]]--;
  if (LCA(x, y) != 1) {
    Difference_Array[Preorden[SparseTable[LCA(x, y)][0]]]--;
  }
}


int main() {
  cin >> n >> m;
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    adjList[x].push_back(y);
    adjList[y].push_back(x);
  }
  Depth[1] = 0; Dfs(1, 1);
  while (m--) {
    Process_Paths();
  }
  for (int i = 0; i < 2*Mxn; i++) {
    psum[i] = (i ? psum[i - 1] : 0)  + Difference_Array[i];
  }
  for (int i = 1; i <= n; i++) {
    cout << psum[Postorden[i]] - psum[Preorden[i] - 1] << " ";
  }
}

