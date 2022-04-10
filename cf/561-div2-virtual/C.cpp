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
  ll n, ans = 0; cin >> n; vi a(n); 
  for (auto &e : a) {
    cin >> e; e = abs(e);
  }
  sort(all(a));
  for (int i = 0; i < n; i++) {
    int val = upper_bound(all(a), 2*a[i]) - a.begin() - 1;
    ans += abs(val - i);
  }
  cout << ans;
}
