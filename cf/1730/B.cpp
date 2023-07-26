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
    int n; cin >> n; vector<long double> V(n), T(n);
    for (auto &e : V) cin >> e;
    for (auto &e : T) cin >> e;
    sort(V.begin(), V.end());
    long double ans = 0;
    long double time = -1;
    long double new_ans;

    for (int i = 0; i < n; i++) {
      time = max(T[i] + abs(ans - V[i]), time);
    }
    for (ll i = 31; i > -25; i--) {
      if (i < 0) {
        long double k = 1<<abs(i);
        new_ans = ans + 1/k;
      } else new_ans = ans + (1<<i);

      long double new_time = -1;
      for (int j = 0; j < n; j++) {
        new_time = max(T[j] + abs(new_ans - V[j]), new_time);
      }
      if (new_time < time) {
        time = new_time;
        ans = new_ans;
      }
     
    }
    cout << setprecision(7) << ans << endl;

  }
}
