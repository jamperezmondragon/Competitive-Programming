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
 
int const Mxn = 2e5 + 1;
ll BIT[Mxn];
ll qu(int i, ll val = 0) {
  for (; i > 0; i -= i&-i) val += BIT[i];
  return val;
}
void upd(int i, ll val) {
  for (; i < Mxn; i += i&-i) BIT[i] += val;
}
int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    int n, k; cin >> n >> k; vi a(n); in(a);
    ll ans = 0;
    vl v;
    for (int i = 0; i < n; i++) {
      ll aux = qu(a[i] + k) - qu(max(a[i] - k, 1));
      v.push_back(-aux);
      upd(a[i], aux + 1); ans += aux;
    }
    for (int i = 0; i < n; i++) {
      upd(a[i], v[i]);
    }
    for (int i = 0; i < n; i++) {
      ll aux = qu(a[i] + k) - qu(a[i] - 1);
      ans -= aux*(aux - 1)/2;
    }
    cout << ans << endl;
  }
}
