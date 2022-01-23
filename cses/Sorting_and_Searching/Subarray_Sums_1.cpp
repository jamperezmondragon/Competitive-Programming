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
  int n, x; cin >> n >> x; vector<int> vec(n);
  map<ll, int> vals; vals[0] = 1; ll ans = 0, psum = 0;
 
  for (auto &e : vec) cin >> e;
 
  for (auto e : vec) {
    psum += e; ans += vals[psum - x]; vals[psum]++;
  }
 
  cout << ans;
}
