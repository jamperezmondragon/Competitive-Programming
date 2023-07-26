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
    int n; cin >> n; vi a(n); in(a);
    vi b(n + 1, a[0]);
    for (int i = 1; i < n; i++) {
      b[i] = a[i - 1]*a[i]/__gcd(a[i], a[i - 1]);
    }
    b[n] = a[n - 1];
    bool ans = true;
    for (int i = 0; i < n; i++) {
      ans &= (__gcd(b[i], b[i + 1]) == a[i]);
    }
    cout << ((ans) ? "YES\n" : "NO\n");
  }
}
