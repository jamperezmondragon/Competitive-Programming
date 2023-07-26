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
 
int const Mxn = 2e5 + 1;
vector<vector<int>> Adj;
vector<ll> A(Mxn);
vector<ll> B(Mxn);
vector<int> Ans(Mxn);

vector<ll> V;

void dfs(int node = 1, int parent = 1, int d = 0) {
  A[node] += A[parent]; B[node] += B[parent];
  V.push_back(B[node]);
  Ans[node] = upper_bound(all(V), A[node]) - V.begin();
  for (auto child : Adj[node]) {
    dfs(child, node, d + 1);
  }
  V.pop_back();
}


int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    int n; cin >> n;
    Adj.clear(), Adj.resize(n + 1);

    for (int i = 2; i <= n; i++) {
      int x; cin >> x >> A[i] >> B[i];
      Adj[x].push_back(i);
    }
    A[1] = 0, B[1] = 0;
    dfs();
    for (int i = 2; i <= n; i++) {
      cout << Ans[i] - 1 << " ";
    }
    cout << endl;
  }
}
