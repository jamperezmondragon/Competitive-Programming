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
 
ll const MOD = 998244353;
int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  ll n; cin >> n; 
  ll ans = 1;
  for (ll i = 1; i <= n/3; i++) {
    vector<ll> a(3); 
    for (auto &e : a) cin >> e;
    sort(all(a));
    ll aux = 1; aux += (a[0] == a[1]); aux += (a[0] == a[2]);
    ans *= aux; ans %= MOD;
    ans *= i; ans %= MOD;
  }
  ll aux = 1;
  for (ll i = 1; i <= n/6; i++) {
    aux *= i; aux %= MOD; aux *= i; aux %= MOD;
  }
  ll aux2 = 1;
  for (ll i = 0; i < 32; i++) {
    if ((MOD-2)&(1<<i)) aux2 *= aux;
    aux *= aux; aux2 %= MOD; aux %= MOD;
  }
  ans *= aux2; ans %= MOD;
  cout << ((ans + MOD)%MOD)%MOD << endl;
}
