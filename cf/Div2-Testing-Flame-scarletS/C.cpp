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
    int n; cin >> n;
    int l = 1, r = n;
    set<int> s;
    while (l < r) {
      int p = (l + r)/2;
      int cnt = 0;
      cout << "? " << l << " " << p << endl;
      for (int i = l; i <= p; i++) {
        int k; cin >> k; 
        if (k > p && !s.count(k)) cnt++, s.insert(k);
      }
      if ((l - p + 1 - cnt)&1) r = p;
      else l = p + 1;
    }
    cout << "! " << l << endl;
  }
}
