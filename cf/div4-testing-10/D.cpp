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
    int x, y; cin >> x >> y;
    int a[2], b[2];
    a[0] = a[1] = b[0] = b[1] = 0;
    while (x%2 == 0) {
      a[0]++; x /= 2;
    }
    while (x%3 == 0) {
      a[1]++; x /= 3;
    }
    while (y%2 == 0) {
      b[0]++; y /= 2;
    }
    while (y%3 == 0) {
      b[1]++; y /= 3;
    }
    if (x != y) {
      cout << "NO\n"; continue;
    }
    if (a[1] >= b[1] && b[0] >= a[0] && a[1] >= b[1] + b[0] - a[0]) cout << "YES\n";
    else cout << "NO\n";
  }
}
