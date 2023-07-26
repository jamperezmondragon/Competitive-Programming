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
 
bool query(set<int> X) {
  cout << "? " << sz(X) << " ";
  for (auto e : X) cout << e << " ";
  cout << endl;
  string s; cin >> s;
  return (s == "YES");
}

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  int n; cin >> n; 
  int ans = 0;
  for (int j = 0; j < 17; j++) {
    set<int> X;
    for (int i = 1; i <= n; i++) {
      if ((i>>j)&1) X.insert(i);
    }
    if (sz(X) == 0) continue;
    if (query(X)) ans += (1<<j);
  }
  for (int j = 0; j < 17; j++) {
    set<int> X;
    for (int i = 1; i <= n; i++) {
      if ((i>>j)&1 == (ans>>j)&1) X.insert(i);
    }
    if (sz(X) == 0) continue;
    bool first = query(X);
    bool second = query(X);
    if (first == second) {
      ans ^= (((int)(!first))<<j);
    }
    if (first != second) {
      if ((ans>>j)&1) ans -= (1<<j);
      else ans += (1<<j);
    }
  }
  cout << "! " << ans << endl;
  cout << "! " << ans + (1<<17) << endl;
}
