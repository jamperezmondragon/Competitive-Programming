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
    int n; char c; cin >> n >> c;
    string s; cin >> s;
    stack<int> S;
    if (c == 'g') {
      cout << 0 << endl;
      continue;
    }
    int ans = 0;
    int last = -1;
    for (int i = 0; i < 2*n; i++) {
      if (s[i%n] == 'g' && last != -1) {
        ans = max(abs(last - i), ans);
        last = -1;
      }
      if (s[i%n] == c && last == -1) last = i;
    }
    cout << ans << endl;
  }
}
