#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const Mxn = 2e5 + 10;
// WA
int n, x, y;
int D[Mxn], V[Mxn];
vector<int> Adj[Mxn];

void dfs(int node, int parent, int val) {
  V[node] = val;
  for (auto child : Adj[node]) {
    if (child == parent) continue;
    dfs(child, node, 1^val);
  }
}

int main() {
  cin.tie(0), ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    cin >> x >> y;
    Adj[x].push_back(y);
    Adj[y].push_back(x);
    D[x]++, D[y]++;
  }
  if (n == 2) {
    cout << "2 2\n1 1"; return 0;
  }
  pair<ll , ll> A, B;
  dfs(1, 1, 1);
  for (int i = 1; i <= n; i++) {
     A.second += (V[i] ? D[i] : 1);
     A.first += V[i];
  }
  cout << endl;
  for (int i = 1; i <= n; i++) {
    cout << (V[i] ? D[i] : 1) << " ";
  }
  dfs(1, 1, 0);
  for (int i = 1; i <= n; i++) {
     B.second += (V[i] ? D[i] : 1);
     B.first += V[i];
  }
  cout << endl;
  for (int i = 1; i <= n; i++) {
    cout << (V[i] ? D[i] : 1) << " ";
  }
  cout << endl;
  if (A < B) dfs(1, 1, 1);
  A = {0, 0};
  for (int i = 1; i <= n; i++) {
     A.second += (V[i] ? D[i] : 1);
     A.first += V[i];
  }
  cout << A.first << " " << A.second << endl;
  for (int i = 1; i <= n; i++) {
    cout << (V[i] ? D[i] : 1) << " ";
  }
}
