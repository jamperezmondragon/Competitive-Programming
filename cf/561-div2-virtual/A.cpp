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
  int n, ans = 0; cin >> n; map<char, int> mp;
  for (int i = 0; i < n; i++) {
    string s; cin >> s; mp[s[0]]++;
  }
  for (auto e : mp) {
    int val = e.second/2;
    int val1 = e.second - val;
    ans += val*(val - 1)/2 + val1*(val1 - 1)/2;
  }
  cout << ans << endl;
}
