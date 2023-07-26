#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)a.size()

int dfs(vector<int> V, int depth = 30) {
  if (depth == -1) return 0;
  vector<int> L, R;
  for (auto e : V) {
    if ((e>>depth)&1) R.push_back(e);
    else L.push_back(e);
  }
  if (!sz(L)) return dfs(R, depth - 1);
  if (!sz(R)) return dfs(L, depth - 1);
  return (min(dfs(L, depth - 1), dfs(R, depth - 1))|(1<<depth));
}

int main() {
  int n; cin >> n;
  vector<int> V(n); 
  for (auto &e : V) cin >> e;
  cout << dfs(V) << endl;
}
