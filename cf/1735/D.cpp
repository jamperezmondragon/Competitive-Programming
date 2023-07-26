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
  int n, k; cin >> n >> k;
  map<vector<int>, bool> ex;
  map<vector<int>, int> cnt;
  vector<vector<int>> V;

  for (int i = 0; i < n; i++) {
    vector<int> A(k);
    for (int f = 0; f < k; f++) {
      cin >> A[f];
    }
    ex[A] = true;
    V.push_back(A);
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++)  {
      vector<int> A(k);
      for (int f = 0; f < k; f++) {
        A[f] = (2*(V[i][f] + V[j][f]))%3;
      }
      if (ex[A])  {
        cnt[A]++;
      }

    }
  }
  ll ans = 0;
  for (auto [x, y] : cnt) {
    //for (auto e : x) cout << e << " ";
    //cout << endl;
    //cout << y << endl;
    ans += y*(y - 1)/2;
  }
  cout << ans << endl;
}
