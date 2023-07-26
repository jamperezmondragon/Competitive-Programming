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

int N, M;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  Testcase {
    int n, m; cin >> n >> m; vi degree(n + 1, 0), freq(n + 1, 0);
    for (int i = 0; i < m; i++) {
      int x, y; cin >> x >> y;
      degree[x]++, degree[y]++;
    }
    for (int i = 1; i <= n; i++) {
      freq[degree[i]]++;
    }
    vi v;
    for (int i = 1; i <= n; i++) {
      if (freq[i]) v.push_back(i);
    }
    if (sz(v) == 2) {
      cout << v.back() << " " << v.back() - 1 << endl;
    } else {
      int x, y;
      for (auto e : v) {
        if (freq[e] != 1) y = e;
        if (freq[e] == 1) x = e;
      }
      cout << x << " " << y - 1 << endl;
    }
  }
}
