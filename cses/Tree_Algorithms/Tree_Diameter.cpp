#include <bits/stdc++.h>
using namespace std;
int const Mxn = 2e5 + 10;
int n, x, y, extremo = 0;
int Depth[Mxn];
vector<int> adjList[Mxn];

void Dfs(int node, int parent) {
  if (Depth[node] > Depth[extremo]) extremo = node;

  for (auto child : adjList[node]) {
    if (child == parent) continue;
    Depth[child] = Depth[node] + 1;
    Dfs(child, node);
  }
}

int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    adjList[x].push_back(y);
    adjList[y].push_back(x);
  }
  Depth[1] = 0;
  Dfs(1, 1);
  Depth[extremo] = 0;
  Dfs(extremo, extremo);
  cout << Depth[extremo] << endl;
}
