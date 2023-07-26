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
 
int const Mxn = 5e3 + 10; 
int BIT[Mxn];

int get(int i, int sum = 0) {
  for (; i > 0; i -= i&(-i)) sum += BIT[i];
  return sum;
}
void add(int i, int val = 1) {
  for (; i < Mxn; i += i&(-i)) BIT[i] += val;
}

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    ll n, ans = 0; cin >> n; vi a(n); in(a); 
    ll dp[n][n]; memset(BIT, 0, sizeof(BIT));

    for (int l = 0; l < n; l++) {
      dp[l][l] = 0;
      for (int r = l + 1; r < n; r++) {
        dp[l][r] = dp[l][r - 1] + get(a[r]);
      }
      add(a[l]);
    }

    for (int i = 0; i < n; i++) { 
      for (int j = i + 1; j < n; j++) {
        if (a[i] >= a[j]) ans += dp[i][j - 1];
      }
    }

    cout << ans << nl;
  }
}
