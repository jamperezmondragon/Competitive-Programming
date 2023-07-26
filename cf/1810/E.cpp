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
 
const int Mxn = 2e5 + 1;
int leader[Mxn], Sz[Mxn];
void make_set(int x) {leader[x] = x; Sz[x] = 1;}
int find(int x) {
  if (leader[x] == x) return x;
  leader[x] = find(leader[x]);
  return leader[x];
}
int unite(int a, int b) {
  int A = find(a), B = find(b);
  if (A == B) return 0;
  if (Sz[A] < Sz[B]) swap(A, B);
  leader[B] = A; Sz[A] += Sz[B];
  return 1;
}
int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    int n, m; cin >> n >> m;
    vi a(n + 1);
    vector<vector<int>> Adj, V;
    Adj.resize(n + 1, {}); V.resize(n + 1, {});
    for (int i = 1; i <= n; i++) {
      cin >> a[i]; V[a[i]].push_back(i);
    }
    for (int i = 0; i < m; i++) {
      int x, y; cin >> x >> y;
      if (a[x] < a[y]) swap(x, y);
      Adj[x].push_back(y);
      cout << x << " " << y << endl;
    }
    int cnt = n;
    for (int i = 0; i <= n; i++) {
      for (auto node : V[i]) {
        make_set(node);
        for (auto child : Adj[node]) {
          if (Sz[find(child)] >= a[node]) {
            cout << node << " " << child << endl;
            cnt -= unite(node, child);
          }
        }
      }
    }
    cout << ((cnt == 1) ? "YES\n" : "NO\n");
  }
}
