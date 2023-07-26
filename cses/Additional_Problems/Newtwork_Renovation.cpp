#include <bits/stdc++.h>
using namespace std;
const int Mxn = 1e5 + 1;
vector<int> g[Mxn];
vector<int> leafs;
int degree[Mxn];

void dfs(int node = 1, int parent = 1) {
  if (degree[node] == 1) leafs.push_back(node);
  for (auto child : g[node]) {
    if (child == parent) continue;
    dfs(child, node);
  }
}
int main() {
  int n; cin >> n;
  for (int i = 1; i < n; i++) {
    int x, y; cin >> x >> y;
    degree[x]++, degree[y]++;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs();
  cout << (leafs.size() + 1)/2 << endl;
  for (int i = 0; i < (leafs.size() + 1)/2; i++) {
    cout << leafs[i] << " " << leafs[leafs.size()/2 + i] << endl;
  }
}
