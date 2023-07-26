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

vector<int> val;
vector<vector<int>>  adjList;
int ans = 0;

void dfs(int node, int parent) {
  for (auto child : adjList[node]) {
    if (child == parent) continue;
    dfs(child, node);
    val[node] += val[child];
  }
  ans += (!val[node]);
}

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    int n; cin >> n;
    ans = 0;

    val.clear(); val.resize(n + 1);
    adjList.clear(); adjList.resize(n + 1);

    for (int i = 2, x; i <= n; i++) {
      cin >> x; adjList[x].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
      char x; cin >> x;
      val[i] = ((x == 'W') ? 1 : -1);
    }
    dfs(1, 1);
    cout << ans << endl;
  }
}
