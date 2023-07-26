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
    int n, tot = 0; cin >> n;
    for (int i = 1; i < n - 2; i++) {
      tot ^= i; cout << i << " ";
    }
    tot ^= 1<<29; tot ^= 1<<30;
    cout << (1<<29) << " " << (1<<30) << " " << tot << endl;
  }
}
