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
    string s, t; cin >> s >> t; int cnt = 0; bool flag = false;
    if(t == "a") {
      cout << 1 << endl; continue;
    }
    for(auto c : t) {
      if(c == 'a') flag = true;
    }
    if (flag) {
      cout << -1 << endl; continue;
    }
    for(auto c : s) {
      if(c == 'a') cnt++;
    }
    cout << (1LL << cnt) << endl;
  }
}
