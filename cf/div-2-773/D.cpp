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
    int n; cin >> n; vi a(n); map<int, int> mp1; set<pair<int, int>> L;
    for (int i = 0; i < n; i++) {
      cin >> a[i]; mp1[a[i]]++;
    }
    bool flag = false;
    for (auto &e : mp1) {
      if (e.second&1) {
        cout << -1 << endl; flag = true; break;
      } else e.second = -1;
    }
    if (flag) continue;
    for (int i = 0; i < n; i++) {
      if (mp1[a[i]] == -1) mp1[a[i]] = i;
      else next[mp1[a[i]]] = i, mp1[a[i]] = -1;
    }
    for (auto it = next.begin(); it < next.end(); it++) {
      pair<int, int> e = *it; int dist = e.second - e.first + 1;
      cout << dist << endl;
    }
  }
}
