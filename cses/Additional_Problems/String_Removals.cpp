#pragma GCC optimize("unroll-loops", "O3")
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

const ll MOD = 1e9 + 7;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  string S; cin >> S;
  vector<ll> dp(26, 0);
  for (auto e : S) {
    dp[e - 'a']++;
    for (int j = 0; j < 26; j++) {
      if (e - 'a' != j) (dp[e - 'a'] += dp[j]) %= MOD;
    }
  }
  ll ans = 0;
  for (int i = 0; i < 26; i++) (ans += dp[i]) %= MOD;
  cout << ans << '\n';
}
