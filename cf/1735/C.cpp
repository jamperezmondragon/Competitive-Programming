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
    int n; string s, ans = ""; cin >> n >> s;
    int arr[26], rev[26];
    for (int i = 0; i < 26; i++) {
      arr[i] = -1;
      rev[i] = -1;
    }
    for (int i = 0; i < n; i++) {
      if (rev[(int)(s[i] - 'a')] != -1) {
        ans += (char)('a' + rev[(int)(s[i] - 'a')]);
        continue;
      }
      for (int j = 0; j < 26; j++) {
        if (arr[j] == -1)  {
          int cnt = 1, k = (int)(s[i] - 'a');
          while (k != j && k != -1) {
            cnt++; k = arr[k];
          }
          if (k == j && cnt != 26)  continue;
          arr[j] = (int)(s[i] - 'a');
          rev[(int)(s[i] - 'a')] = j;
          ans += (char)('a' + j);
          break;
        }
      }
    }
    cout << ans << endl;
  }
}
