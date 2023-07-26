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

vector<vector<ll>> adjList;
vector<ll> ans;
ll num_Paths = 0;
 
void dfs(ll node, ll parent = -1) {
  if (sz(adjList[node]) == 1 && parent != -1) {
    ans.push_back(node);
    cout << sz(ans) << nl;
    for (auto e : ans) cout << e << " ";
    cout << nl;
    ans.clear(); return;
  }

  ans.push_back(node);

  for (auto child : adjList[node]) {
    if (child == parent) continue;
    dfs(child, node);
  }
}
 
int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);
  Testcase {
    ll n, root; cin >> n;
    ans.clear(); num_Paths = 0;
    adjList.clear(); adjList.resize(n + 1);

    for (int i = 1, x; i <= n; i++) {
      cin >> x;
      if (x == i) root = i;
      else {
        adjList[x].push_back(i);
        adjList[i].push_back(x);
      }
    }

    for (int i = 1; i <= n; i++) {
      if (sz(adjList[i]) == 1 && i != root) num_Paths++;
    }

    if (n == 1) num_Paths = 1;
    cout << num_Paths << nl;
    if (n == 1) cout << "1" << nl << "1" << nl;
    dfs(root);
    cout << nl;
  }
}
