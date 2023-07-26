#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pi = pair<int, int>;
using vii = vector<vector<int>>;
using mii = map<int, int>;
#define in(a) for (auto &e : a) cin >> e
#define sz(x) int((x).size())
#define all(a) a.begin(), a.end()
#define ptp partition_point
#define F first
#define S second
#define Testcase ll t; cin >> t; while (t--)
#define nl "\n"
#define m_p make_pair

void dfs(int node, int parent, vii & g, vi &V) {
  V.push_back(node);
  for (auto child : g[node]) {
    if (child == parent) continue;
    dfs(child, node, g, V);
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tt; 
  int foo;
  for (cin >> tt; tt; tt--) {
    int n; cin >> n;
    if (n == 2) {
      cout << "! 1 2 2 1" << endl;
      cin >> foo;
      continue;
    }
    cout << "+ " << n << endl;
    cin >> foo;
    cout << "+ " << n + 1 << endl;
    cin >> foo;
    vii g(n + 1);
    for (int i = 1; i <= n; i++) {
      if (i < n && i != n - i) g[i].push_back(n - i);
      if (i != n + 1 - i) g[i].push_back(n + 1 - i);
    }
    vi V; dfs(n, n, g, V);
    vi A(n + 1);
    int mx = 0, extremo = 1;
    for (int i = 2; i <= n; i++) {
      cout << "? 1 " << i << endl;
      cin >> A[i];
      if (mx < A[i]) extremo = i, mx = A[i];
    }
    A[extremo] = 0;
    for (int i = 1; i <= n; i++) {
      if (i == extremo) continue;
      cout << "? " << extremo << " " << i << endl;
      cin >> A[i];
    }
    cout << "! ";
    for (int i = 1; i <= n; i++) {
      cout << V[A[i]] << " ";
    }
    reverse(V.begin(), V.end());
    for (int i = 1; i <= n; i++) {
      cout << V[A[i]] << " ";
    }
    cout << endl;
    cin >> foo;
  }
}
