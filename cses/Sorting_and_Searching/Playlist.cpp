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
*/
/* Analisis
* ==========
*
*/
//int const M = 1000000007;
 
int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
 
  int n; cin >> n; vector<int> vec(n);
  set<int> s; int ans = 0;
 
  for (auto &e : vec) cin >> e;
 
  for (int i = 0, j = 0; i < n; i++) {
    if (s.count(vec[i]) == 1) {
      ans = max(ans, (int)s.size());
      while (vec[j] != vec[i]) {
        s.erase(vec[j]); j++; 
      }
      j++; 
    } else s.insert(vec[i]);
  }
  ans = max(ans, (int)s.size());
  cout << ans;
}
