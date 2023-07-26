#include <bits/stdc++.h>
using namespace std;
int const Mxn = 2e5 + 10;
int Subtree_Size[Mxn];
int n, x, y;
vector<int> adjList[Mxn];

void dfs(int node, int parent) {
  Subtree_Size[node] = 1;
  for (auto child : adjList[node]) {
    if (child == parent) continue;
    dfs(child, node);
    Subtree_Size[node] += Subtree_Size[child];
  }
}

int centroid(int node, int parent)  {
  for (auto child : adjList[node]) {
    if (child == parent) continue;
    if (2*Subtree_Size[child] > n) return centroid(child, node);
  }
  return node;
}

int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    adjList[x].push_back(y);
    adjList[y].push_back(x);
  }

  dfs(1, 1);

  cout << centroid(1, 1) << endl;

}
