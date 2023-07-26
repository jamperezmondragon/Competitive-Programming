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
   int n, impar = 0, cnt = 0; cin >> n; string s; cin >> s;
   for (char c : s) impar += ((c - '0')&1);
   if (impar <= 1) {
     cout << "-1\n"; continue;
   }
   for (char c : s) {
     if ((c - '0')&1) { 
       cout << c; cnt++;
     }
     if (cnt == 2) break;
   }
   cout << '\n';
  }
}
