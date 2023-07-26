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
    int n, k, sum = 0, ans; cin >> n >> k; vector<int> V(n);
    for (int i = 0; i < n; i++) {
      char s; cin >> s; 
      if (s == 'W') V[i] = 1;
      else V[i] = 0;
    }
    for (int i = 0; i < k; i++) {
      sum += V[i];
    }
    ans = sum;
    for (int i = k; i < n; i++) {
      sum += V[i] - V[i - k];
      ans = min(ans, sum);
    }
    cout << ans << endl;
  }
}
