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
    int n, k; cin >> n >> k; 
    vector<int> b(51, 0);
    vector<pair<int, int>> A(n);

    for (auto &[x, y] : A) {
      cin >> x >> y;
      if (x > k || y < k) continue;
      for (int i = x; i <= y; i++) b[i]++;
    }

    int aux = 0;

    for (int i = 1; i <= 50; i++) {
      aux += (b[i] >= b[k]);
    }

    cout << ((aux == 1) ? "YES\n" : "NO\n");
  }
}
