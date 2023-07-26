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
    int a, b; cin >> a >> b;
    if (a == 1 || b == 1) {
      cout << "1 \n" << a << " " << b << "\n";
    } else {
      cout << "2\n";
      if (a < b) {
        int c = a - 1; 
        int d = b;
        while (__gcd(c, d) > 1) d--;
        cout << c << " " << d << '\n';
        cout << a << " " << b << '\n';
      } else {
        int c = b - 1; 
        int d = a;
        while (__gcd(c, d) > 1) d--;
        cout << d << " " << c << '\n';
        cout << a << " " << b << '\n';
      }
    }
  }
}
