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
    int n; cin >> n;
    vector<int> A(n), X(n + 1);
    for (int i = 0; i < n; i++) {
      cin >> A[i]; X[A[i]] = i;
    }
    int s = n - 1; 
    set<int> S;
    while (s > 0 && A[s] >= A[s - 1]) s--;
    for (int i = 0; i < s; i++) {
      S.insert(A[i]); s = max(s, X[A[i]]);
    }
    cout << S.size() << endl;
  }
}
