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
    int n; cin >> n;
    vi a(n + 1), idx(n + 1), shift(n + 1);
    for (int i = 0; i < n; i++) {
      cin >> a[i]; idx[a[i]] = i;
    }

    for (int i = n; i > 0; i--) {
      shift[i] = ((idx[i] - i + 1)%i + i)%i;
      for (int j = 1; j <= i; j++) {
        (idx[j] = idx[j] - shift[i] + i)%= i;
      }
    }
    bool flag = false;
    for (int i = 1; i <= n; i++) {
      if (i - idx[i]  != 1) flag = true;
    }
    if (flag) {
      cout << -1 << endl; continue;
    }
    for (int i = 1; i <= n; i++) {
      cout << shift[i] << " ";
    }
    cout << endl;
  }
}
