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
 
int A[1<<19];
int Ma[1<<19], Mi[1<<19];
int n; 
int flag = true;

int dfs(int node) {
  if (node >= n)  return 0;
  int ans = dfs(2*node) + dfs(2*node + 1);

  Mi[node] = min(Mi[2*node], Mi[2*node + 1]);
  Ma[node] = max(Ma[2*node], Ma[2*node + 1]);

  if (Ma[2*node + 1] < Ma[2*node]) {
    ans++; 
    swap(Ma[2*node], Ma[2*node + 1]);
    swap(Mi[2*node], Mi[2*node + 1]);
  }

  if (Ma[2*node] > Mi[2*node + 1]) flag = false;

  return ans;
}

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    cin >> n; flag = true;
    for (int i = 0; i < n; i++) {
      cin >> A[n + i]; Mi[n + i] = Ma[n + i] = A[n + i];
    }
    int ans = dfs(1);
    cout << ((flag) ? ans : -1) << endl; 
  }
}
