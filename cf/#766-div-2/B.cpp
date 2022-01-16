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
* link del problema: https://codeforces.com/contest/1627/problem/B
* submission: https://codeforces.com/contest/1627/submission/142851089
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
        int n, m; cin >> n >> m; vector<int> dist;
        for (int i = 1; i <= n; i++) {
          for (int j = 1; j <= m; j++) {
            int k = max({
                abs(n - i) + abs(m - j),
                abs(n - i) + abs(1 - j),
                abs(1 - i) + abs(m - j),
                abs(1 - i) + abs(1 - j)
                });
            dist.push_back(k);
          }
        }
        sort(all(dist));
        for (int i = 0; i < n*m; i++) {
          cout << dist[i] << " ";
        }
        cout << "\n";
      }
    }
