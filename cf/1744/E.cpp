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
    ll a, b, c, d; cin >> a >> b >> c >> d;
    vl A, B;
    for (ll i = 1; i*i <= a; i++) {
      if (a%i == 0) {
        A.push_back(i); A.push_back(a/i);
      }
    }
    for (ll i = 1; i*i <= b; i++) {
      if (b%i == 0) {
        B.push_back(i); B.push_back(b/i);
      }
    } 
    pair<ll, ll> ans = {-1, -1};
    for (int i = 0; i < sz(A); i++) {
      for (int j = 0; j < sz(B); j++) {
        ll x = A[i]*B[j];
        ll y = a*b/x;
        ll l = x*((a + x)/x);
        ll r = y*((b + y)/y);
        if (l <= c && r <= d) {
          ans = {l, r};
        }
        l = x*((b + x)/x);
        r = y*((a + y)/y);
        if (l <= d && r <= c) {
          ans = {r, l};
        }
      }
    }
    cout << ans.first << " " << ans.second << endl;
  }
}
