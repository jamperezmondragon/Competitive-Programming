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
    int n; cin >> n; vector<int>  V(n), pos(n + 1);
    for (int i = 0; i < n; i++) {
      cin >> V[i]; pos[V[i]] = i + 1;
    }
    vector<pair<int, int>> A(3);
    A[1] = {pos[1], 1}; A[0] = {pos[2], 2}; A[2] = {pos[n], n};
    sort(all(A));
    if (A[1].second == n) cout << pos[1] << " " << pos[2] << endl;
    else cout << pos[n] << " " << A[1].first << endl;
  }
}
