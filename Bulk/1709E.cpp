#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)a.size()
int const Mxn = 2e5 + 1;
int n, ans = 0;
vector<int> Adj[Mxn];
int V[Mxn];
 
set<int> dfs(int node, int parent, int x = 0) {
  set<int> A, A_; bool flag = false;
  x ^= V[node]; A.insert(x);

  for (auto child : Adj[node]) {
    if (child == parent) continue;
    set<int> B = dfs(child, node, x);
    if (sz(A) < sz(B)) swap(A, B);
    for (auto e : B) flag |= A.count(e^V[node]);
    for (auto e : B) A.insert(e);
  }

  if (flag) {
    ans++; return A_;
  }
  return A;
}
 
int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin >> n; 
  for (int i = 1; i <= n; i++) {
    cin >> V[i]; 
  }
  for (int i = 0; i < n - 1; i++) {
    int x, y; cin >> x >> y;
    Adj[x].push_back(y);
    Adj[y].push_back(x);
  }
  dfs(1, 1);
  cout << ans << endl;
}
