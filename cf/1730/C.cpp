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
    string s; cin >> s; int n = sz(s);
    vector<int> S;
    int a[11];
    for (int i = 0; i < 11; i++) a[i] = 0;
    for (int i = 0; i < n; i++) {
      a[s[i] - '0']++;
    }
    int val = 0;
    while (a[val] == 0) val++;
    for (int i = 0; i < n; i++) {
      if ((int)(s[i] - '0') != val) S.push_back((int)(s[i] - '0'));  
    }
    sort(S.begin(), S.end());

    while (a[val]--) cout << val;
    for (auto e : S) cout << min(e + 1, 9);
    cout << endl;
  }
}
