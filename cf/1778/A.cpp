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
    int n; cin >> n; vi a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i]; sum += a[i];
    }
    bool flag = false;
    for (int i = 0; i < n - 1; i++) {
      if (a[i] == -1 && a[i + 1] == -1) flag = true;
    }
    if (flag) {
      cout << sum + 4 << '\n'; continue;
    }
    for (int i = 0; i < n - 1; i++) {
      if (a[i] + a[i + 1] == 0) flag = true;
    }
    if (flag) {
      cout << sum << '\n'; continue;
    } else {
      cout << sum - 4 << '\n'; continue;
    }
  }
}
