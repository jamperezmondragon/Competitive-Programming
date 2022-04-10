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
    ll n, m, W = 0; cin >> n >> m;
    vector<pi> points1(m), points2(m), ans(n);
    set<int> s; mii mp;
    for (int i = 0; i < m; i++) {
      cin >> points1[i].first >> points1[i].second;
      points2[i].first = points1[i].second;
      points2[i].second = points1[i].first;
      mp[points1[i].first] = i+1;
    }
    sort(all(points2));
    sort(all(points1));
    for (int i = 0; i < 2*n; i++) {
      W += points2[i].first;
      s.insert(points2[i].second);
    }

    int i = 0;
    for (int cnt = 0; i < m && cnt < n; i++) {
      if (s.count(points1[i].first)) ans[cnt++].first = mp[points1[i].first];
    }
    for (int cnt = n - 1; i < m && cnt >= 0; i++) {
      if (s.count(points1[i].first)) ans[cnt--].second = mp[points1[i].first];
    }
    cout << W << endl;
    for (auto e : ans) {
      if (e.first > e.second) swap(e.first, e.second);
      cout << e.first << " " << e.second << endl;
    }
    cout << endl;
  }
}
