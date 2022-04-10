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
  char v[5] = {'a', 'e', 'i', 'o', 'u'}; //el burro sabe más que tú!
  int k, n = 0, m = 0; cin >> k;
  for (int i = 5; i*i <= k; i++) {
    if (k%i == 0) n = i, m = k/i;
  }
  if (n) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << v[(i + j)%5];
      }
    }
  } else {
    cout << -1 << endl;
  }
}
