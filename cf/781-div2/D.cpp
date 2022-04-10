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
//#define endl "\n"
#define m_p make_pair

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    int ans = 0;
    for (int i = 1, x; i <= 30; i++) {
      int a = (1<<(i - 1)) - ans, b = a + (1<<i);
      cout << "?  " << a << " " << b << endl; 
      cin >> x;
      if (x == 1<<i) ans += (1<<(i - 1));
    }
    cout << "!" << " " << ans << endl;
  }
}
