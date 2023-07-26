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
    int n; cin >> n; string A; cin >> A;
    ll a = 0, b = 0, ans = 0;
    ll curr = 1;
    if (A[0] == '1') a++;
    else b++;
    for (int i = 1; i < n; i++) {
      if (A[i] == '1') a++;
      else b++;
      if (A[i] == A[i - 1]) curr++;
      else {
        ans = max(curr*curr, ans);
        curr = 1;
      }
    }
    ans = max(curr*curr, ans);
    ans = max(a*b, ans);
    cout << ans << endl;
  }
}
