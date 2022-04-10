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
  Testcase {
    int n, K = 0, cnt = 1; cin >> n; vi a(n + 1, 0); 
    for (int i = 0, x; i < n; i++) {
      cin >> x; a[x]++;
    }
    sort(all(a)); reverse(all(a));
    for (int i = 0; i < n; i++) {
      if (a[i] == 0) break;
      K++;
    }
    priority_queue<int> Q;
    for (int i = 0; i < n; i++) {
      if (a[i] == 0) break;
      Q.push(a[i] + K - i);
    }
  }
}

