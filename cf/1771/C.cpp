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
     ll n, m; cin >> n >> m;
     vector<bool> active(m, false);
     vector<vector<pair<ll, ll>>> V(n + 1);
     ll ans = n, j = 0;

     for (ll i = 0; i < m; i++) {
       ll x, y; cin >> x >> y;
       if (x > y) swap(x, y);
       V[x].push_back({i, 1});
       V[y].push_back({i, 0});
     }
     for (ll i = 1; i <= n; i++) {
       while (j < n) {
         bool fail = false;
         for(auto [id, ini] : V[j + 1]) {
           if(!ini && active[id]) {
             fail = true; break;
           }
         }
         if (fail) break;
         for (auto [id, ini] : V[j + 1]) {
           if (ini == 0) continue;
           active[id] = true;
         }
         j++;
       }
       ans += j - i;
       for(auto [id, ini] : V[i]) {
         if (ini != 1) continue;
         active[id] = false;
       }
     }
     cout << ans << endl;
  }
}
