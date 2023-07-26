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
    ll n, a = 0, b = 0, s = 1; cin >> n;
    ll po = 1;
    while (n) {
      int x = n%10;
      if (x&1) {
        if (s) {
          a += ((x + 1)/2)*po;
          b += (x/2)*po;
          s ^= 1;
        } else {
          b += ((x + 1)/2)*po;
          a += (x/2)*po;
          s ^= 1;
        }
      } else {
        a += po*(x/2); b += po*(x/2);
      }
      n /= 10; po *= 10;
    }
    cout << a << " " << b << endl;
  }
}
