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
 
int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    int n; cin >> n; vector<int> V(n); vector<pair<int, int>> C;
    for (int i = 0; i < n; i++) {
      cin >> V[i];
    }
    for (int i = 0; i < n; i++) {
      int k = 1;
      while (k <= V[i]) k *= 2;
      if (k/2 == V[i]) continue;
      C.push_back({i + 1, k - V[i]});
    }
    cout << sz(C) << endl;
    for (auto [x, y] : C) cout << x << " " << y << endl;
  }
}
