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
 
const ll MOD = 1e9 + 7;
ll pow(ll a, ll b = MOD - 2, ll ans = 1) {
  for (ll i = 0, e = a; i < 32; i++, e *= e, e %= MOD) {
    if ((b>>i)&1) (ans *= e) %= MOD;
  }
  return ans;
}

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    ll n, m, k; cin >> n >> m >> k;
    vi a(n); in(a);
    ll ans = pow(k, m), facto = 1, bino = 1, pote = pow(k - 1, m);
    ans -= pote;
    for (ll i = 1; i < n; i++) {
      (facto *= i) %= MOD;
      (bino *= (m - i + 1)) %= MOD;
      (pote *= pow(k - 1)) %= MOD;
      ans -= (((bino*pow(facto))%MOD)*pote)%MOD;
      ans %= MOD;
    }
    cout << (ans%MOD + MOD)%MOD << endl;
  }
}
