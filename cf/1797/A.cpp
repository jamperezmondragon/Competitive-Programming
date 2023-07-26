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
    int n, m; cin >> n >> m;
    int x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
    vector<pair<int, int>> esquinas;
    esquinas.push_back({n, m});
    esquinas.push_back({n, 1});
    esquinas.push_back({1, m});
    esquinas.push_back({1, 1});
    bool flag = false;
    for (auto [x, y] : esquinas) {
      if (x == x1 && y == y1) flag = true;
    }
    for (auto [x, y] : esquinas) {
      if (x == x2 && y == y2) flag = true;
    }
    if (flag) {
      cout << 2 << endl; continue;
    }
    if (x1 == n || x1 == 1 || y1 == 1 || y1 == m || x2 == n || x2 == 1 || y2 == m || y2 == 1) {
      cout << 3 << endl; continue;
    }
    cout << 4 << endl;
  }
}
