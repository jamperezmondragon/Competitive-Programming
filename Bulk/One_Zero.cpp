#include <bits/stdc++.h>
using namespace std;

int main() {
  int tt; cin >> tt; while (tt--) {
    cout << endl;
    int n; cin >> n;
    cout << endl;
    vector<bool> vis(n);
    vector<int> parent(n);
    vector<int> path(n);
    queue<int> Q; Q.push(1);
    vis[1] = true;
    while (Q.size()) {
      int v = Q.front(); Q.pop();
      if (!vis[(v*10)%n]) {
        vis[(v*10)%n] = true;
        Q.push((v*10)%n); parent[(v*10)%n] = v; path[(v*10)%n] = 0;
      }
      if (!vis[(v*10 + 1)%n]) {
        vis[(v*10 + 1)%n] = true;
        Q.push((v*10 + 1)%n); parent[(v*10 + 1)%n] = v; path[(v*10 + 1)%n] = 1;
      }
    }
    vector<int> V;
    for (int x = 0; x != 1; x = parent[x]) V.push_back(path[x]);
    V.push_back(1);
    reverse(V.begin(), V.end());
    for (auto e : V) cout << e;
    cout << endl;
  }
}
