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
    int n; cin >> n; int a = 0, b = 0, ans = 0;
    vector<int> s1(n), s2(n);
    for (auto &e : s1) cin >> e;
    for (auto &e : s2) cin >> e;
    for (int i = 0; i < n; i++) {
      if (s1[i] == s2[i]) {
        ans++; continue;
      }
      if (s1[i] == 0) a++;
      else b++;
    }

    cout << ans + max(a, b) + min(a, b)/2 << endl;
  }
}
