#include <bits/stdc++.h>
using namespace std;
int const Mxn = 2e5 + 10;
int n, x, y, endpoint = 0;
int Depth[Mxn], ans[Mxn];
vector<int> adjList[Mxn];

void Dfs(int node, int parent) {
  //update possible endpoint.
  if (Depth[node] > Depth[endpoint]) endpoint = node;
  for (auto child : adjList[node]) {
    if (child == parent) continue;
    //compute depth from root (distance from root)
    Depth[child] = Depth[node] + 1;
    Dfs(child, node);
  }
  //Update answer for current node.
  ans[node] = max(ans[node], Depth[node]);
}


int main() {
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    adjList[x].push_back(y);
    adjList[y].push_back(x);
  }

  //First dfs from a random node, to find one  of the endpoints of the diameter.
  Depth[1] = 0;
  Dfs(1, 0);
  //Second dfs, to find the distances from each node to that endpoint, and to find the second endpoint.
  Depth[endpoint] = 0;
  Dfs(endpoint, 0);
  //Third dfs, to get distances from second endpoint to every other node.
  Depth[endpoint] = 0;
  Dfs(endpoint, 0);

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << " ";
  }
}
