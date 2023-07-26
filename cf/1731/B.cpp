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

ll const MOD = 1e9 + 7;
 
int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  ll xd = 166666668LL;
  Testcase {
    ll n; cin >> n; 
    ll ans = (n*(n + 1))%MOD;
    (ans *= 2*n + 1) %= MOD;
    (ans += (((n - 1)*n)%MOD)*2*(n + 1)) %= MOD;
    (ans *= xd ) %= MOD;
    (ans *= 2022LL) %= MOD;
    cout << ans << endl;
  }
}
