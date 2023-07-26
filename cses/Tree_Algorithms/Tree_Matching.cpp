#include <bits/stdc++.h>
using namespace std;
int const Mxn = 2e5 + 10;
int dp1[Mxn], dp2[Mxn];
int n, x, y;
vector<int> adjList[Mxn];

void dfs(int node, int parent) {
  for (auto child : adjList[node]) {
    if (parent == child) continue;
    dfs(child, node);
  }
  for (auto child : adjList[node]) {
    if (parent == child) continue;
    dp1[node] += max(dp1[child], dp2[child]);
  }
  for (auto child : adjList[node]) {
    if (parent == child) continue;
    dp2[node] = max(dp2[node], 1 + dp1[child] + dp1[node] - max(dp1[child], dp2[child]));
  }
}

int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    adjList[x].push_back(y);
    adjList[y].push_back(x);
  }
  dfs(1, 1);
  cout << max(dp1[1], dp2[1]) << endl;
}
