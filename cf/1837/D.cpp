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
    int n; cin >> n; string S; cin >> S; vi A(n + 1, 0);
    for (int i = 0; i < n; i++) {
      A[i + 1] = A[i] + ((S[i] == '(') ? 1 : -1);
    }
    if (A[n] != 0) {
      cout << -1 << endl; continue;
    }
    vector<int> ans(n + 1);
    int last = 1;
    int mi = 1e7;
    for (int i = 1; i <= n; i++) {
      mi = min(A[i], mi);
      if (A[i] == 0) {
        for (int j = last; j <= i; j++) {
          ans[j] = ((mi == 0) ? 1 : 2);
        }
        last = i + 1;
        mi = 1e7;
      } 
    }
    int cnt[3] = {0, 0, 0};
    for (int i = 1; i <= n; i++) cnt[ans[i]]++;
    if (cnt[2] == n || cnt[1] == n) {
      cout << 1 << endl;
      for (int i = 0; i < n; i++) {
        cout << 1 << " ";
      }
      cout << endl;
    } else {
      cout << 2 << endl;
      for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
      }
      cout << endl;
    }
  }
}
