#include <bits/stdc++.h>
using namespace std;

string s, aux = "", lastone = ""; int n;
bool vis[8];

void dfs() {
  for (int i = 0; i < n; i++) {
    if (vis[i]) continue;
    string A = aux;
    aux += s[i]; vis[i] = true;
    dfs();
    aux = A; vis[i] = false;
  }
  if ((int)aux.size() == n) {
    if (aux == lastone) return;
    cout << aux << endl; lastone = aux;
    return;
  }
}

int main() {
  cin >> s; sort(s.begin(), s.end());
  n = (int)s.size();
  dfs();
}
