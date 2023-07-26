#include <bits/stdc++.h>
using namespace std;
int const Mxn = 2e5 + 10;
int n;
int next[Mxn], ans[Mxn], vis[Mxn];

void visitar(int v, int cnt = 0) {

  while (vis[v]) {
    vis[v] = cc + cnt++; v = next[v];
  }
  if (vis[v] < cc) {

  } else {

  }
  cc += cnt;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> next[i]; Adj[next[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    if (vis[i]) continue;
    visitar(i, ++cc);
  }
}
