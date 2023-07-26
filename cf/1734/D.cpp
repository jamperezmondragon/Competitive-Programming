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
    int n, k; cin >> n >> k; 
    vector<ll> V(n);
    for (auto &e : V) cin >> e;
    bool flag = false;
    ll sum = 0; k--;
    for (int i = k, j = k + 1; i >= 0;) {
      if (sum + V[i] < 0) {
        if (j == n) break;
        if (sum + V[j] < 0) break;
        sum += V[j++];
      } else {
        sum += V[i--];
      }
      if (i == -1) flag = true;
    }
    for (int i = k - 1, j = k; j < n;) {
      if (sum + V[j] < 0) {
        if (i == -1) break;
        if (sum + V[i] < 0) break;
        sum += V[i--];
      } else {
        sum += V[j++];
      }
      if (j == n) flag = true;
    }
    cout << (flag ? "YES\n" : "NO\n");
  }
}
