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

bool debug = false;
#define DEBUG if (debug) cout << 

namespace stress_test {
  auto gen_test(int n) -> vector<pair<int, int>> { // generates random tree with n nodes using prufer code. 
    vector<int> prufer(n - 2), cnt(n + 1, 0);
    vector<pair<int, int>> A;
    for (auto &e : prufer) e = (rand()%n + n)%n;
    for (auto &e : prufer) e++;
    priority_queue<int> Q; 
    for (int i = 0; i < n - 2; i++) {
      cnt[prufer[i]]++;
    }
    for (int i = 0; i < n - 2; i++) {
      if (cnt[prufer[i]] == 0) Q.push(prufer[i]);
    }
    for (int i = 0; i < n - 2; i++) {
      int x = Q.top(); Q.pop();
      A.push_back({x, prufer[i]});
      if (--cnt[prufer[i]] == 0) Q.push(prufer[i]);
    }
    return A;
  }
}

namespace correct_sol {
  vector<int> P, depth;
  vector<vector<int>> g;
  void dfs(int node = 1, int parent = 0) {
    P[node] = parent; depth[node] = depth[parent] + 1;
    for (auto child : g[node]) {
      if (child == parent) continue;
      dfs(child, node);
    }
  }
  int solve(int n, vector<pair<int, int>> A) {
    g.clear(); g.resize(n + 1); P.clear(); P.resize(n + 1); depth.clear(); depth.resize(n + 1, 0);
    for (auto [x, y] : A) {
      g[x].push_back(y);
      g[y].push_back(x);
    }
    ll true_ans = 0;
    for (int mask = 0; mask < (1<<n); mask++) {
      ll ans = 0;
      for (int u = 1; u <= n; u++) {
        for (int v = 1; v <= n; v++) {
          if (v == u) {
            if (!((mask>>u)&1)) ans++;
            continue;
          }
          ll cnt[2] = {0, 0};
          for (int x = u, y = v; x != y; x = P[x]) {
            if (depth[x] < depth[y]) swap(x, y);
            cnt[(mask>>x)&1]++;
          }
          if (!cnt[0]) ans++;
          if (!cnt[0] && !cnt[1]) ans++;
        }
      }
      true_ans = max(true_ans, ans);
    }
    return true_ans;
  }
}

namespace my_sol {

  int dfs(int node = 1, int parent = 0, int depth = 0, int cnt = 0) {
    if (depth&1) cnt++;
    for (auto child : g[node]) {
      if (child == parent) continue;
      cnt += dfs(child, node, depth + 1);
    }
    return cnt;
  }

  int solve(int n, vector<pair<int, int>> A) {
    cnt = 0; g.clear(); g.resize(n + 1); 
    for (auto [x, y] : A) {
      g[x].push_back(y);
      g[y].push_back(x);
    }

  }
}  
for (int i = 0; i < n; i++)
int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
  }
}
