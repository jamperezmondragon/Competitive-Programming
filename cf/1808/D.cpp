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
int const Mxn = 2e5 + 1; 
 
struct queries {
  int a, b, coef;
  bool operator < (const & queries A) {return a < A.a;}
};

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  int n, k; cin >> n >> k;
  vector<int> V(n); in(V);
  vector<queries> Q[2];
  for (int i = 0; i < n; i++) {
    int y = max(n - 1, i + k - 1);
    queries X;
    X.a = y; X.b = V[i], X.coef = 1;
    Q[i&1].push_back(X);
    if (i < k/2 - 1) X.a = k - i;
    else X.a = min(i + k/2, n - 1);
    X.b = V[i]; X.coef = -1;
    Q[i&1].push_back(X);
  }
  sort(all(Q[0]));
  sort(all(Q[1]));
  vector<int> bucket(0, Mxn);
}
