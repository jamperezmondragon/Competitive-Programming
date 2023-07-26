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
    int n; string s; cin >> s; n = sz(s);
    int a = 0, b = 0; bool flag = true;

    if (s[0] == 'B') flag = false;
    else a++;

    for (int i = 1; i < n; i++) {
      if (s[i] == 'B') {
        b++;
        if (b > a) flag = false;
      } else a++;
    }
    if (s[n - 1] == 'A') flag = false;
    cout << ((flag)  ? "YES\n" : "NO\n");
  }
}
