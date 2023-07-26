#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const Mxn = 2e5 + 10;
ll dp[Mxn], Subtree_Size[Mxn];
ll n, x, y;
vector<int> adjList[Mxn];

void Dfs1(int node, int parent) {
  dp[node] = 0;
  Subtree_Size[node] = 1;
  for (auto child : adjList[node]) {
    if (child == parent) continue;
    Dfs1(child, node);
    dp[node] += dp[child] + Subtree_Size[child];
    Subtree_Size[node] += Subtree_Size[child];
  }
}

void Dfs(int node, int parent) {
  if (node != 1) dp[node] = dp[parent] + n - 2*Subtree_Size[node];
  for (auto child : adjList[node]) {
    if (child == parent) continue;
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

  Dfs1(1, 1);
  Dfs(1, 1);
  for (int i = 1; i <= n; i++) {
    cout << dp[i] << " ";
  }
}

