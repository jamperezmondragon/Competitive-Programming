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
#define endl "\n"
#define m_p make_pair

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    int x, y; cin >> x >> y;
    if (x == 0 && y == 0) {
      cout << 0 << endl; continue;
    }
    if ((int)sqrt(x*x + y*y)*(int)sqrt(x*x + y*y) == (x*x + y*y)) {
      cout << 1 << endl; continue;
    }
    cout << 2 << endl; 
  }
}
