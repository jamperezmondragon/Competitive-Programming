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
    int n, k; cin >> n >> k; vi A(k); in(A);
    vi D(k, A[0]);
    bool flag = true;
    for (int i = 1; i < k; i++) {
      D[i] = A[i] - A[i - 1];
      if (D[i] < D[i - 1]) flag = false;
    }
    if (k == 1) {
      cout << "yes\n"; continue;
    }
    if (n - k > 0 && (n - k)*D[1] < D[0]) flag = false;
    cout << ((flag) ? "yes\n" : "no\n");
    
  }
}
