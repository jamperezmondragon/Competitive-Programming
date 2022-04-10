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
    int n; cin >> n;
    string s1, s2, s3, ans1, ans2, ans3;
    cin >> s1 >> s2 >> s3;
    for (int i = 0; i < 2*n; i++) {
      if (s1[i] == s2[i]) ans1 += s1[i];
      if (s1[i] != s2[i]) ans1 += "10";
      if (s1[i] == s3[i]) ans2 += s1[i];
      if (s1[i] != s3[i]) ans2 += "10";
      if (s2[i] == s3[i]) ans3 += s2[i];
      if (s2[i] != s3[i]) ans3 += "10";
    }
    if (sz(ans2) > sz(ans3)) swap(ans2, ans3);
    if (sz(ans1) > sz(ans2)) swap(ans2, ans1);
    cout << ans1 << endl;
  }
}
