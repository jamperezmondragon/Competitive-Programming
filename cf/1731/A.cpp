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
    ll n; cin >> n; vl a(n); in(a); 
    ll ans = 1;
    for (int i = 0; i < n; i++) ans = a[i]*ans;
    ans += n - 1;
    ans *= 2022LL;
    cout << ans << endl;
  }
}
