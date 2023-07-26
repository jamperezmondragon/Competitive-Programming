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
    string s; cin >> s; 
    map<char, int> mp;
    set<char> S;
    for (int i = 0; i < sz(s); i++) {
      S.insert(s[i]); mp[s[i]]++;
    }
    int cnt = (mp['Y'] > 0) + (mp['e'] > 0) + (mp['s'] > 0);
    if (cnt == sz(S)) cout << "YES\n";
    else cout << "NO\n";
  }
}
