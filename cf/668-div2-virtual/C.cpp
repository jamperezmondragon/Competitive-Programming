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
    int n, k, cnt0 = 0, cnt1 = 0; string s; cin >> n >> k >> s;
    bool flag = true;
    for (int i = 0; i < k; i++) {
      char val = '?';
      for (int j = i; j < n; j += k) {
        if (val != '?' && s[j] != val) {
          flag = false; break;
        }
        val = s[j];
      }
      if (val == '?') continue;
      (val == '1') ? cnt1++ : cnt0++;
    }
    if (max(cnt1, cnt0) > k/2) flag = false;
    cout << ((flag) ? "YES" : "NO") << endl;
  }
}
