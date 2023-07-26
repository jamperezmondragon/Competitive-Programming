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
 
ll mcm(ll a, ll b) {
  return a*b/__gcd(a, b);
}



int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    int n; string s; cin >> n >> s;
    int p[n + 1]; bool vis[n + 1];
    for (int i = 1; i <= n; i++) {
      cin >> p[i];
      vis[i] = false;
    }
    ll ans = 1;
    vector<vector<int>> Vec;
    for (int i = 1; i <= n; i++) {
      if (vis[i]) continue;
      int j = i; ll k = 1;
      Vec.push_back({});
      while (p[j] != i) {
        Vec.back() += s[j - 1];
        vis[j] = true;
        j = p[j]; k++;
      }
      Vec.back() += s[j - 1];
      vis[j] = true;
    }

    for (auto e : Vec) {
      int m = sz(e);
      int val = m;
      for (int i = 0; i*i <= m; i++) {
        if (m%i != 0) continue;
        if (check(e, i)) val = min(val, i);
        if (check(e, n/i)) val = min(val, n/i);
      }
      ans = mcm(m, );
    }
  }
}
