#include <bits/stdc++.h>
using namespace std;
const int Mxn = 1e5 + 1;
bool vis[Mxn];
int depth[Mxn];
int A[2*Mxn], B[2*Mxn], C[2*Mxn];
vector<int> g[Mxn];

void dfs(int node = 1, int d = 1) {
  depth[node] = d++;
  vis[node] = true;
  for (auto child : g[node]) {
    if (vis[child]) continue;
    dfs(child, d);
  }
}

int main() {
  int n, m; cin >> n >> m;
  set<pair<int, int>> S;
  for (int i = 0; i < m; i++) {
    cin >> A[i] >> B[i];
    if (A[i] < B[i]) swap(A[i], B[i]);
    if (S.count({A[i], B[i]})) continue;
    S.insert({A[i], B[i]});
    g[A[i]].push_back(B[i]);
    g[B[i]].push_back(A[i]);

  }
  dfs();
  for (int i = 0; i < m; i++) {
    if (depth[A[i]] > depth[B[i]]) swap(B[i], A[i]);
    cout << A[i] << " " << B[i] << endl;
  }
}
