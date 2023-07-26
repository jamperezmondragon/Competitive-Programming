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
  int n; cin >> n; 
  string s; cin >> s;
  int x = 0;
  while (x < n && s[x] == '0') x++;
  if (x == n) {
    cout << 0; return 0;
  }
  s = s.substr(s, n - x);
  n = sz(s);
  while (x < n && s[x] == 0) x++;
  if (x == n) {
    cout << s; return 0;
  }
  string ans = s;
  for (int i = 0; i < x; i++) {
    string aux = s;
    for (int j = x; j < n; j++) {
      if (aux[j - i] == '1' && aux[j] == '0') aux[]
    }
  }
  cout << ans;
}
