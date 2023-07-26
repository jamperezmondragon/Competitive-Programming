#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using ll = long long int;
#define sz(a) (int)a.size()

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  string s; cin >> s;
  vi f(26, 0);
  int k = 0, cnt = 0;
  for (auto e : s) f[e - 'a']++;
  for (auto e : f) k += (e != 0);
  map<vi, int> mp;
  vi v(26, 0); ll ans = 0; mp[v]++;
  for (auto e : s)  {
    cnt += (++v[e - 'a'] == 1);
    if (cnt == k) {
      for (int i = 0; i < 26; i++) {
        cnt -= (v[i] == 0) ? 0 : (--v[i] == 0);
      }
    }
    ans += mp[v]; mp[v]++;
  }
  cout << ans << '\n';
}
