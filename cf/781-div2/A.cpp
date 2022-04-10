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
    if (n&1) {
      cout << (n - 1)/2 << " " << (n - 1)/2 - 1 << " " << 1 << " " << 1;
    } else {
      if ((n/2)%2 == 0) {
      cout << n/4  << " " << n/4 << " "  << n/4 << " " << n/4;
      } else {
        cout << n/2 << " " << n/2 - 2 << " " << 1 << " " << 1;
      }
    }
    cout << endl;
  }
}
