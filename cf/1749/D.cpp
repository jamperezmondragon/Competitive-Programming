#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
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
 
int const MOD = 998244353;
int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  ll n, m; cin >> n >> m; vl dp(n + 1, 1);
  dp[1] = m%MOD;
  ll curr = 1;
  vector<bool> is_prime(n + 1, true);
  for (ll i = 2; i <= n; i++) {
    if (curr > m) goto thing;
    if (is_prime[i]) curr *= i;
    for (ll j = i; j <= n; j += i) is_prime[j] = false;
    thing:
    dp[i] = ((dp[i - 1])*((m/curr)%MOD)) % MOD;
  }
  curr = 0;
  ll x = m%MOD;
  m %= MOD;
  for (int i = 1; i <= n; i++) {
    (curr += x) %= MOD;
    (x *= m) %= MOD;
  }
  for (int i = 1; i <= n; i++) {
    (curr -= dp[i]) %= MOD;
  }
  cout << (curr + MOD)%MOD << endl;
}
