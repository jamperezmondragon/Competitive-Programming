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
    int cnt = 0, ans = 0, rem = 0, n; string s; cin >> n >> s;
    for (auto c : s) if(c != '(') cnt++; 
    for (int i = 0; i < n; i++) {

      if (i + 1 < n && s[i] == ')' && s[i + 1] == '(') {
        if (cnt > 1) {
          ans++;
          while(s[i + 1] == '(') i++;
          cnt -= 2; i++;
        }
        else {
          rem = n - i; break;
        }
      }
      else {
        if (i + 1 < n) {
          ans++; 
          if (s[i] != '(') cnt--;
          if (s[i + 1] != '(') cnt--;
          i++;
        }
        else {
          rem = 1;
          break;
        }
      }
    }
    cout << ans << ' ' << rem << endl;
  }
}
