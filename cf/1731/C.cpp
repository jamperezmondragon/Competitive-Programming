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
 
int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    ll n; cin >> n; vector<ll> a(n); in(a);
    ll bs = 1;
    while (bs <= n) bs <<= 1;
    vector<ll> b(bs, 0);

    b[0]++; b[a[0]]++;
    for (ll i = 1; i < n; i++) {
      a[i] = a[i - 1]^a[i];
      b[a[i]]++;
    }
    ll ans = n*(n + 1)/2;
    ll diff = 0;
    for (ll i = 0; i < bs; i++) {
      for (ll j = 1; j*j < bs; j++) {
        diff += b[i^(j*j)]*b[i];
      }
    }
    diff /= 2;
    for (int i = 0; i < bs; i++) {
      diff += b[i]*(b[i] - 1)/2;
    }
    cout << ans - diff << endl;
  }
}
