    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    #define in(a) for (auto &e : a) cin >> e
    #define all(a) a.begin(), a.end()
    #define lb lower_bound
    #define ub upper_bound
    #define F first
    #define S second
/* Informative
* ==============
* Status: AC
* link del problema: https://codeforces.com/contest/1627/problem/A
* submission: https://codeforces.com/contest/1627/submission/142837284
*/
/*
* Comments
* =========
*/
/* Analisis
* ==========
*
*/

     
    int main() {
      cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
      ll T; cin >> T;
      while (T--) {
        int n, m, r, c; cin >> n >> m >> r >> c;
        bool flag0 = false, flag1 = false, flag2 = false;
        for (int i = 1; i <= n; i++) {
          for (int j = 1; j <= m; j++) {
            char k; cin >> k;
            if (k == 'B') flag2 = true;
            if ((i == r || j == c) && k == 'B') flag1 = true;
            if (i == r && j == c && k == 'B') flag0 = true;
          }         
        }
        if (flag0) {
          cout << 0 << "\n"; continue;
        }
        if (flag1) {
          cout << 1 << "\n"; continue;
        }
        if (flag2) {
          cout << 2 << "\n"; continue;
        }
        if (!flag2) {
          cout << -1 << "\n"; continue;
        }
      }
    }
