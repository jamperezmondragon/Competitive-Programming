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
    string s; cin >> s;
    vector<int> a(10, 0);
    for (int i = 0; i < sz(s); i++)  {
      a[s[i] - '0']++;
    }
    bool flag_3 = false, flag_4 = false;
    for (int i = 0; i < 10; i++) {
      if (a[i] == 3) flag_3 = true;
      if (a[i] == 4) flag_4 = true;
    }
    if (flag_4) {
      cout << -1 << '\n';
    } else if (flag_3) {
      cout << 6 << '\n';
    } else {
      cout << 4 << '\n';
    }
  }
}
