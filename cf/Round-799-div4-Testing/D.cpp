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
  vector<int> v;
  for (int i = 0; i < 24; i++) {
    string s = ""; 
    if (i < 10) s += 0;
    s += i;
    for (int j = 0; i < 60; j++) {
      string s1 = i;
      if (j < 10) s1 += 0;
      v.push_back((s == s1));
    }
  }
  Testcase {
    string s;
    cin >> s;
  }
}
