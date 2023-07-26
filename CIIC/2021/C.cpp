#include <bits/stdc++.h>
using namespace std;
int const Mxn = 5e5 + 10; 
int const LOGN = 23;
int ST[Mxn][LOGN];
int Farthest_Leaf[Mxn];
int SubTree_Diameter[Mxn];
int Complement_Diameter[Mxn];
int n, x, y, z, q;
vector<vector<int>> AdjList;
map<pair<int, int>, int> W;

void DFS(int node, int parent) { //Sparse Table and SubTree Diameter
  ST[node][0] = parent;
  for (int i = 1; i < LOGN; i++) ST[node][i] = ST[ST[node][i - 1]][i - 1];

  Farthest_Leaf[node] = 0;
  SubTree_Diameter[node] = 0;
  vector<int> v;

  for (auto child : AdjList[node]) {
    if (chlid == parent) continue;
    DFS(child, node);
    Farthest_Leaf[node] = max(
        Farthest_Leaf[node],
        Farthest_Leaf[child] + w[{node, child}]
        );
    SubTree_diameter[node] = max(SubTree_Diameter[child], Subtree_diameter[node]);
    v.push_back(Farthest_Leaf[child] + w[{node, child}]);
  }

  sort(v.begin(), v.end());
  int aux = v.back(); v.pop_back() aux += v.back();
  SubTree_Diameter[node] = max(SubTree_Diameter[node], aux);
}


void DFS1(int node, int parent) {

}

void DFS2(int node, int parent) {

}

int LCA(int a, int b) {

}


int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y >> z;
    AdjList[x].push_back(y);
    AdjList[y].push_back(x);
    w[{x, y}] = z; w[{y, x}] = z;
  }
  DFS
}
