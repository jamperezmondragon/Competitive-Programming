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
    int n, m; cin >> n >> m;
    string s, s2; cin >> s >> s2;
    int aux = 0;
    for (int i = 1; i < n; i++) {
      aux += (s[i - 1] == s[i]);
    }
    for (int i = 1; i < m; i++) {
      aux += (s2[i - 1] == s2[i]);
    }
    if (aux == 0) {
      cout << "YES\n"; continue;
    } 
    if (aux >= 2) {
      cout << "NO\n"; continue;
    }
    cout << ((s.back() == s2.back()) ? "NO\n" : "YES\n");
  }
}
