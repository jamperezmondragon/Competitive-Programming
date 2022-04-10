#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  string s; cin >> s; map<int, bool> mp; int n = (int)s.size();
  mp[0] = (s[0] == '0') ? 0 : 1;
  mp[n] = n;

  for (int i = 1; i < n; i++) {
    if (s[i] != s[i - 1]) {
      if (mp.count(i - 1)) mp[i - 1] = (s[i - 1] == '0') ? 0 : 1;
      mp[i] = (s[i] == '0') ? 0 : 1;
    }
  }

  for (auto e : mp) {
    cout << e.first << " ";
  }

}
