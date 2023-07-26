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
    int n; cin >> n;
    int time, h, m;
    cin >> h >> m;
    time = 60*h + m;
    int ans = 1440;
    for (int i = 0; i < n; i++) {
      cin >> h >> m;
      int x = 60*h + m - time;
      if (x < 0) x += 1440;
      ans = min(ans, x);
    }
    cout << ans/60 << " " << ans%60 << endl;
  }
}
