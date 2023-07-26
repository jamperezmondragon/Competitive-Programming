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
int const Mxn = 2e5 + 10; 
vector<vector<int>> adjList;
set<int> s;
int SubTree[Mxn];
bool contain_final[Mxn];
int n, k, x, y, a, b, ans = 0;

void DFS(int node, int parent) {
  SubTree[node] = s.count(node);
  contain_final[node] = (node == y);
  for (auto child : adjList[node]) {
    if (child == parent) continue;
    DFS(child, node);
    SubTree[node] += SubTree[child];
    contain_final[node] += contain_final[child];
  }
}

void dfs(int node, int parent) {
  int aux = 0;
  ans++;
  for (auto child : adjList[node]) {
    if (child == parent) continue;
    if (SubTree[child] == 0 && !contain_final[child]) continue;
    if (contain_final[child]) {
      aux = child; continue;
    }
    dfs(child, node); 
    ans++;
  }
  if (aux == 0) return;
  dfs(aux, node);
}


int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    cin >> n >> k >> x >> y;
    adjList.clear(); adjList.resize(n + 1);
    s.clear(); ans = 0;

    for (int i = 0, aux; i < k; i++) {
      cin >> aux; s.insert(aux);
    }

    for (int i = 2; i <= n; i++) {
      cin >> a >> b;
      adjList[a].push_back(b);
      adjList[b].push_back(a);
    }
    DFS(x, 0);
    dfs(x, 0);
    cout << ans - 1 << nl;
  }
}
