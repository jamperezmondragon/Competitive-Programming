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
   int x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if(y1 == y2 && y3 < y1) {
      cout << abs(x2 - x1) << endl; continue;
    }
    if(y2 == y3 && y1 < y2) {
      cout << abs(x2 - x3) << endl; continue;
    }
    if(y3 == y1 && y2 < y1) {
      cout << abs(x3 - x1) << endl; continue;
    }
    cout << 0 << endl;
  }
}
