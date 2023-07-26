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
    int n; cin >> n; vi a(n), b(n); 
    in(a);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt += (a[i]%5 == 0);
    }
    if (cnt != n && cnt) { 
      cout << "NO\n"; continue;
    }
    if (cnt == n) {

    } else {
      for (int i = 0; i < n; i++) {
        int x = a[i]/10 + ti[a[i]%10];
        c[x]++;
      }
      if (c[x])
    }
  }
}
