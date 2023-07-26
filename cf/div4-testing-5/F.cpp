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
    int n, q; cin >> n >> q; vector<ll> A(n), Ans(q);

    vector<pair<int, int>> K(q);

    for (auto &e : A) cin >> e;

    for (int i = 0; i < q; i++) {
      cin >> K[i].first; K[i].second = i;
    }

    sort(K.begin(), K.end());

    ll sum = 0, j = 0;

    for (int i = 0; i < n; i++) {
      while (A[i] > K[j].first && j < q) {
        Ans[K[j].second] = sum; j++;
      }
      sum += A[i];
    }

    while (j < q) Ans[K[j++].second] = sum;

    for (auto e : Ans) cout << e << " ";
    cout << endl;
  }
}
