#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//debuging 
const bool DEB = false;
#define DEBUG if (DEB) 
/* Informative
* ==============
* Status: 
* link del problema: 
* submission:
*/
/*
* Comments
* =========
*
*/
/* Analisis
* ==========
*
*/
//int const M = 1000000007;
 
int main() {
  int n, m, x; cin >> n >> m; multiset<int, greater<int>> s;
  while (n--) cin >> x, s.insert(x);
  while (m--) {
    cin >> x;
    auto it = s.lower_bound(x);
    if (it == s.end()) cout << -1 << "\n";
    else {
      cout << *it << "\n";
      s.erase(it);
    }
  }
}
