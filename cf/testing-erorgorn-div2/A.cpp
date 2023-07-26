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
#define Testcase ll tt; cin >> tt; while (tt--)
#define nl "\n"
#define m_p make_pair
 
int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    int n, sum = 0; cin >> n; vector<int> V(n);
    for (auto &e : V) {
      cin >> e; sum += e; sum &= 1;
    }
    if (!sum) {
      cout << 0 << endl; continue;
    }
    int ans = 40;
    for (int i = 0; i < n; i++) {
      int k = 0;
      while (((V[i]>>k)&1) == (V[i]&1)) k++;
      ans = min(k, ans);
    }
    cout << ans << endl;
  }
}
