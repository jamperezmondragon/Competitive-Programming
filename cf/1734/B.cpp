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
 
int const Mxn = 1e6 + 1;
int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    int n; cin >> n; string s; cin >> s;
    ll ans = 0;
    string k = "a" + s;
    for (int i = 1; i <= n; i++) {
      if (k[i] == '1') continue;
      for (int j = i; j <= n; j += i) {
        if (k[j] == '1') break;
        if (k[j] == '2') continue;
        k[j] = '2';
        ans += i;
      }
    }
    cout << ans << endl;
  }
}
