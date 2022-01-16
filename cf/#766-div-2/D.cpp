    #include <bits/stdc++.h>
    using namespace std;
    using ll = long long;
    #define in(a) for (auto &e : a) cin >> e
    #define all(a) a.begin(), a.end()
    #define ptp partition_point
    #define F first
    #define S second
     
/* Informative
* ==============
* Status: AC
* link del problema: https://codeforces.com/contest/1627/problem/D
* submission: https://codeforces.com/contest/1627/submission/142896266
*/
/*
* Comments
* =========
*/
/* Analisis
* ==========
* Darse cuenta que si un número se puede agregar entonces es el gcd de todos sus multiplos en el arreglo
* Después de eso solo es hacer una criba y ya
*/

     
    int main() {
      cin.tie(0); ios_base::sync_with_stdio(0);
      int n, maxi = 0; cin >> n; vector<int> arr(n); unordered_set<int> s;
      for (int i = 0; i < n; i++) {
        cin >> arr[i];
        s.insert(arr[i]);
        maxi = max(maxi, arr[i]);
      }
      int ans = 0;
      for (int i = 1; i <= maxi; i++) {
        if (s.count(i) != 0) continue;
        int g = 0;
        for (int j = 0; j <= maxi; j += i) {
          if (s.count(j) != 1) continue;
          if (g == 0) g = j;
          else g = __gcd(g, j);
        }
        if (g == i) ans++;
      }
      cout << ans;
    }
