#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
const int Mxn = 1e5 + 1;
multiset<int> g[Mxn];
int deltadeg[Mxn];
vector<int> path;
 
void dfs(int node) {
  while (sz(g[node])) {
    auto it = g[node].begin();
    int child = *it;
    g[node].erase(it);
    dfs(child);
  }
  path.push_back(node);
}
 
int main() {
  int n, m; cin >> n >> m;
  g[n].insert(1);
  deltadeg[1]--; deltadeg[n]++;
  for (int i = 0; i < m; i++) {
    int a, b; cin >> a >> b;
    deltadeg[a]++; deltadeg[b]--;
    g[a].insert(b);
  }
  int cnt = 0, x;
  for (int i = 1; i <= n; i++) {
    cnt += (deltadeg[i] != 0);
  }
  if (cnt) {
    cout << "IMPOSSIBLE\n"; return 0;
  }
  cnt = g[n].count(1);
  dfs(1);
  reverse(all(path));
  if (sz(path) != m + 2) {
    cout << "IMPOSSIBLE\n"; return 0;
  }
  for (int i = 1; i < sz(path); i++) {
    if (path[i - 1] == n && path[i] == 1) cnt--;
    if (cnt == 0) {
      x = i;
      break;
    }
  }
  for (int i = x; i < sz(path); i++) {
    cout << path[i] << " ";
  }
  for (int i = 1; i < x; i++) {
    cout << path[i] << " ";
  }
}
 
