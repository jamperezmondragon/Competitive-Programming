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
    int n; cin >> n; vector<pair<ll, ll>> A(n), B(n);
    for (auto &[x, y] : A) cin >> x >> y; 
    ll tot_area = 0;
    for (auto [x, y] : A) tot_area += x*y;
    set<pair<ll, ll>> S;

    sort(all(A)); reverse(all(A));
    pair<ll, ll> a = {A[0].first, tot_area/A[0].first};
    bool flag = true;
    for (int i = 0; i < n; i++) {
      if (a.first == A[i].first) {
        a.second -= A[i].second;
      } else if (a.second == A[i].second) {
        a.first -= A[i].first;
      } else {
        flag = false;
        break;
      }
    }
    if (flag && A.back() == a) {
      S.insert({A[0].first, tot_area/A[0].first});
    } 

    for (auto &[x, y] : A) swap(x, y);
    sort(all(A)); reverse(all(A));
    a = {A[0].first, tot_area/A[0].first};
    flag = true;
    for (int i = 0; i < n; i++) {
      if (a.first == A[i].first) {
        a.second -= A[i].second;
      } else if (a.second == A[i].second) {
        a.first -= A[i].first;
      } else {
        flag = false;
        break;
      }
    }
    if (flag && a.second == 0 || ) {
      S.insert({tot_area/A[0].first, A[0].first});
    } 
    cout << sz(S) << '\n';
    for (auto [x, y] : S) {
      cout << x << " " << y << '\n';
    }
  }
}
