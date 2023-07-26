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
    int n, counter = 0; string s; cin >> n >> s; 

    for (int i = 1; i <= 100; i++) {

      map<char, int> mp; set<char> S;

      for (int j = 0; j < i; j++) {
        mp[s[j]]++; S.insert(s[j]);
      }

      bool flag = true;
      for (auto [x, y] : mp) {
        if (y != 0 && y > (int)S.size()) flag = false;
      }
      counter += flag;

      for (int j = 0; j + i < n; j++) {
        mp[s[j]]--; mp[s[j + i]]++;
        if (mp[s[j]] == 0) S.erase(s[j]);
        if (mp[s[j + i]] == 1) S.insert(s[j + i]);
        flag = true;
        for (auto [x, y] : mp) {
          if (y != 0 && y > (int)S.size()) flag = false;
        }
        counter += flag;
      }
    }

    cout << counter << endl;
  }
}
