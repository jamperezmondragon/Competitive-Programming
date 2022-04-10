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
  int n, k, offset = 0, sum = 0; cin >> n >> k; vi a(n), v(n, 0); in(a);
  int K = k;
  for (int i = n - 1; i >= 0; i--) {
    if (K < k) K--;
    a[i] -= offset;
    if (a[i] <= 0) continue;
    v[i] = a[i]/K + ((a[i]%K == 0) ? 0 : 1); 
    sum += v[i];
    offset += K*v[i];
    offset -= sum;
    if (i + k < n) sum -= v[i + k];
  }
  int ans = 0;
  for (auto e : v) ans += e;
  cout << ans;
}
