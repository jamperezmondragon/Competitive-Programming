#include <bits/stdc++.h>
using namespace std;
int const Mxn = 2e5 + 10;
int const LOGN = 23;
int n, q, x, y;
int SparseTable[Mxn][LOGN + 1], Depth[Mxn];
vector<int> adjList[Mxn];

void Dfs(int node, int parent) {

  SparseTable[node][0] = parent;
  for (int i = 1; i <= LOGN; i++) {
    SparseTable[node][i] = SparseTable[SparseTable[node][i - 1]][i - 1];
  }

  for (auto child : adjList[node]) {
    if (child == parent) continue;
    Depth[child] = Depth[node] + 1;
    Dfs(child, node);
  }

}

int Jump(int node, int salto) {
  for (int i = LOGN; i >= 0; i--) {
    if ((salto>>i)&1) node = SparseTable[node][i];
  }
  return node;
}

int LCA(int a, int b) {
  if (Depth[a] < Depth[b]) swap(a, b);
  int salto = Depth[a] - Depth[b];
  a = Jump(a, salto);
  if (a == b) return a;

  for (int i = LOGN; i >= 0; i--) {
    if (SparseTable[a][i] != SparseTable[b][i]) {
      a = SparseTable[a][i]; b = SparseTable[b][i];
    }
  }
  return SparseTable[a][0];
}

void queries() {
  cin >> x >> y;
  cout << Depth[x] + Depth[y] - 2*Depth[LCA(x, y)] << endl;
}

int main () {
  cin >> n >> q;
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    adjList[x].push_back(y);
    adjList[y].push_back(x);
  }
  memset(Depth, 0, sizeof(Depth));
  Dfs(1, 1);
  while (q--) {
    queries();
  }
}
