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
  int n; cin >> n; vector<pair<int, int>> vec(n);
  for (auto &e : vec) {
    cin >> e.second >> e.first;
  }
  sort(vec.begin(), vec.end());
  int ans = 0, last = 0;
  for (auto e : vec) {
    if (e.second < last) continue;
    ans++; last = e.first;
  }
  cout << ans;
}
