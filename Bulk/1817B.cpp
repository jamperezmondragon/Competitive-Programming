#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)a.size()

vector<int> euler, tin;
vector<vector<int>> g;
vector<bool> vis;
int OG, indx;

void dfs(int node, int parent = 0) {
  vis[node] = true;
  tin[node] = sz(euler);
  euler.push_back(node);
  for (auto child : g[node]) {
    if (child == parent) continue;
    if (child == OG) indx = tin[node];
    if (vis[child]) continue;
    dfs(child, node);
  }
  euler.push_back(node);
}

int main() {
  int tt; cin >> tt; while (tt--) {
    int n, m, x, y; cin >> n >> m;
    g.clear(); g.resize(n + 1); vis.clear(); vis.assign(n + 1, false);
    vector<int> deg(n + 1, 0);
    for (int i = 0; i < m; i++) {
      cin >> x >> y;
      g[x].push_back(y);
      g[y].push_back(x);
      deg[x]++, deg[y]++;
    }
    bool flag = false;
    vector<pair<int, int>> P;
    for (OG = 1; OG <= n; OG++) {
      if (deg[OG] < 4) continue;
      vis.assign(n + 1, false);
      tin.assign(n + 1, 0);
      euler.clear();
      indx = -1; dfs(OG);
      if (indx == -1) continue;
      flag = true;
      vector<int> a(n + 1, 0);
      int first = -1;
      for (int i = 0; i <= indx; i++) {
        if (a[euler[i]] == 0 && first == -1) first = i;
        if (first != -1 && euler[i] == euler[first]) first = -1;
        a[euler[i]] ^= 1;
      }
      int A = -1, B, aux;
      for (auto e : g[OG]) {
        if (e == euler[first] || e == euler[indx]) continue;
        if (A == -1) A = e;
        else B = e;
      }
      if (tin[A] > tin[B]) swap(A, B);
      if (a[A]) {
        aux = euler[indx];
        indx = tin[A];
        A = aux;
      } else if (a[B]) {
        aux = euler[indx];
        indx = tin[B];
        B = aux;
      } 
      int last = OG;
      P.push_back({OG, A});
      P.push_back({OG, B});
      for (int i = 1; i <= indx; i++) {
        if (a[euler[i]]) {
          P.push_back({last, euler[i]}), last = euler[i];
        }
      }
      P.push_back({last, OG});
      break;
    }
    if (flag) {
      cout << "YES\n" << sz(P) << endl;
      for (auto [w, z] : P) cout << w << " " << z << endl;
    } else cout << "NO\n";
  }
}
