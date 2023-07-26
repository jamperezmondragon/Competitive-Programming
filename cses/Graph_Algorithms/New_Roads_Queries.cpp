#include <bits/stdc++.h>
using namespace std;
int const Mxn = 2e5 + 10;
int const LOGN = 17;
int n, m, q, x, y;
vector<vector<pair<int, int>>> Adj(Mxn);

// Make Tree;
int leader[Mxn], Size[Mxn];
void make_set(int v) {
  leader[v] = v; Size[v] = 1;
}

//standard DSU with path compression
int find_set(int v) {
  if (leader[v] == v) return v;
  return (leader[v] = find_set(leader[v]));
}

//unite sets, like kruskal after I do the DSU part I add an edge to my adjlist
void unite_sets(int a, int b, int C) {
  int A = find_set(a), B = find_set(b);
  if (A == B) return;
  if (Size[A] < Size[B]) swap(A, B);
  leader[B] = A, Size[A] += Size[B];

  Adj[a].push_back({b, C});
  Adj[b].push_back({a, C});
}

//LCA and query;
pair<int, int> ST[LOGN + 1][Mxn]; // pairs<int, int> {node, max in the path from node to (1<<i)-th ancestor}
int Depth[Mxn];

//DFS to precompute my sparse table and depth array
void dfs(int node, int parent, int W) {
  Depth[node] = Depth[parent] + 1;
  ST[0][node] = {parent, W};

  for (int i = 1; i <= LOGN; i++) { //compute sparse table
    ST[i][node] = {ST[i - 1][ST[i - 1][node].first].first, 
      max(ST[i - 1][node].second, ST[i - 1][ST[i - 1][node].first].second)};
  }

  for (auto [child, w] : Adj[node]) {
    if (child == parent) continue;
    dfs(child, node, w);
  }
}
pair<int, int> LA(int v, int k, int C = 0) { //level ansestor, returns {ansestor, max edge in jump} 
  for (int i = LOGN; i >= 0; i--) {
    if ((k>>i)&1) {
      C = max(C, ST[i][v].second), v = ST[i][v].first;
    }
  }
  return {v, C};
}
int LCA(int A, int B) { // LCA, returns the max in the path basically 

  if (Depth[A] < Depth[B]) swap(A, B); // the putting both nodes at the same depth parth
  pair<int, int> aux = LA(A, Depth[A] - Depth[B]); 
  if (aux.first == B) return aux.second;
  A = aux.first; int ans = aux.second;

  for (int i = LOGN; i >= 0; i--) { // the binary search part
    if (ST[i][A].first != ST[i][B].first) {
      ans = max({ans, ST[i][A].second, ST[i][B].second});
      A = ST[i][A].first, B = ST[i][B].first;
    }
  }

  ans = max({ans, ST[0][A].second, ST[0][B].second});
  return ans;
}

int query(int a, int b) { // query
  if (find_set(a) != find_set(b)) return -1;
  return LCA(a, b);
}


int main() {
  std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false);
  cin >> n >> m >> q;
  
  // setup the DSU
  for (int i = 1; i <= n; i++) {
    make_set(i);
  }
  //compute the MST
  for (int i = 1; i <= m; i++) {
    cin >> x >> y;
    unite_sets(x, y, i);
  }

  //conect all the roots of the MST of each component to a new node (node 0) 
  //to make everything easier.
  for (int i = 1; i <= n; i++) {
    if (leader[i] != i) continue;
    Adj[0].push_back({i, 0});
    Adj[i].push_back({0, 0});
  }
  Depth[0] = -1;
  dfs(0, 0, 0);
  
  //process queries
  while (q--) {
    cin >> x >> y;
    cout << query(x, y) << endl;
  }
}
