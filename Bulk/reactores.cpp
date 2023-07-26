#include <bits/stdc++.h>
using namespace std;
int const Mxn = 100001; 
int cnt[Mxn];
vector<bool> vis;
int greta_thunberg = 0, mf = 0, greta_thunberg2 = 0;
char bullshit[3] = {'B', 'G', 'S'};

vector<int> Adj[Mxn];

void dfs(int node) {
  cnt[node]++;
  if (vis[node]) return;
  vis[node] = true;
  if (Adj[node].size() == 0) greta_thunberg++;

  for (auto child : Adj[node]) {
    dfs(child);
  }
}

void dfs1(int node) {
  cnt[node]--; 
  if (cnt[node] > 0 || vis[node]) return;
  vis[node] = true;
  for (auto child : Adj[node]) {
    dfs1(child);
  }

}

int main() {
  memset(cnt, 0, sizeof(cnt));
  vis.assign(Mxn, false);

  int n, m, r; cin >> n >> m >> r;

  for (int i = 0, x, y; i < m; i++) {
    cin >> x >> y; Adj[x].push_back(y);
  }
  dfs(r);

  vis.assign(Mxn, false);
  dfs1(r);
  for (int i = 1; i <= n; i++) {
    mf = min(2, max(mf, cnt[i]));
    greta_thunberg2 += (cnt[i] && Adj[i].size() == 0);
  }

  cout << bullshit[mf] << endl << greta_thunberg << " " << greta_thunberg2;

}
