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
    int n; cin >> n; vector<int> A(n);
    in(A);
    int cnt = 0;
    for (auto e : A) if (e == 2) cnt++;
    int x = *max_element(all(A));
    if (x > 2 || cnt > 1 || (cnt == 1 && x == 2 && n > 2)) {
      cout << -1 << endl; continue;
    }
    if (cnt == 1) {
      int k = A.begin() - max_element(all(A));
      for (int j = 1; j < (1<<(n)); j++) {
        int e = (j^(j>>1));
        if (e == (1<<(n - 1)) - 1) {
          for (int i = 0; i < n; i++) {
            if (i == k) cout << 2 << " ";
            else cout << 1 << " ";
          }
          cout << endl;
          for (int i = 0; i < n; i++) {
            if (i == k) cout << 0 << " ";
            else cout << 1 << " ";
          }
          cout << endl;
          continue;
        }
        for (int i = 0; i < n; i++, e >>= 1) {
          if (i == k) {
            cout << 2 << " "; continue;
          }
          if (e&1) cout << 0 << " ";
          else cout << 1 << " ";
        }
        cout << endl;
        for (int i = 0; i < n; i++, e >>= 1) {
          if (e&1) cout << 0 << " ";
          else cout << 1 << " ";
        }
        cout << endl;
      }
      for (int i = 0 ; i < n; i++) {
        if (i != k) cout << 0 << " ";
        else cout << 2 << " ";
      }
      cout << endl;
    } else {
      for (int j = 1; j < (1<<n); j++) {
        int e = (j^(j>>1));
        if (e == (1<<n) - 1) {
          for (int i = 0; i < n; i++) {
            cout << 1 << " ";
          }
          cout << endl;
          continue;
        }
        for (int i = 0; i < n; i++, e >>= 1) {
          if (e&1) cout << 0 << " ";
          else cout << 1 << " ";
        }
        cout << endl;
      }
    }
  }
}
