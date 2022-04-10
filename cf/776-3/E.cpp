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
#define endl "\n"
#define m_p make_pair

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    int n, d; cin >> n >> d; vi a(n), diff(n); in(a);
    sort(all(a));
    diff[0] = a[0]; 
    for (int i = 1; i < n; i++) {
      diff[i]  = a[i] - a[i - 1];
    }
    int mini = INT_MAX, maxi = -1;
    int val, val1;
    for (int i = 0; i < n; i++) {
      mini = min(diff[i], mini);
      maxi = max(diff[i], maxi);
      if (diff[i] == mini) {
        val = i;
      }
      if (diff[i] == maxi) {
        val1 = i;
      }
    }
    sort(all(diff));
    int pos1 = min({(a[val - 1] + a[val + 1])/2, maxi/2, d - a[n - 1] - 1, diff[1]});
    int pos2 = min({(a[val1 - 1] + a[val1 + 1])/2, maxi/2, d - a[n - 1] - 1, diff[1]});
    cout << max(pos1, pos2) << endl;
  }
}
