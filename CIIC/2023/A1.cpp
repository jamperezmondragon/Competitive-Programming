#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const Mxn = 2e5 + 1;


int val[Mxn];
bool vis[Mxn];
vector<int> g[Mxn];
ll curr = 0;

struct obj {
  int u;
  bool operator<(const obj & A) const {return val[u] > val[A.u];}
};

ll bfs(int src) {
  for (int i = 0; i < Mxn; i++) vis[i] = false;
  priority_queue<obj> Q;
  vis[src] = true;
  ll ans = val[src];
  for (auto child : g[src]) Q.push({child});

  while (size(Q)) {
    auto [node] = Q.top(); Q.pop();
    if (val[node] >= ans) continue;
    ans += val[node]; vis[node] = true;
    for (auto child : g[node]) {
      if (!vis[child]) Q.push({child});
    }
  }
  return ans;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n; 
  for (int i = 1; i < n; i++) {
    int x, y; cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) cin >> val[i];
  for (int i = 1; i <= n; i++) {
    cout << bfs(i) << " ";
  }
}
