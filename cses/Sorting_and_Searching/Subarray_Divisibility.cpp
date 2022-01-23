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
  int n; cin >> n; vector<int> vals(n, 0); vals[0] = 1;
  ll ans = 0, psum = 0;
  for (int i = 0; i < n; i++) {
    int a; cin >> a; psum += a; vals[(psum%n + n)%n]++;
  }
  for (ll e : vals) {
    ans += e*(e - 1)/2;
  }
  cout << ans;
}
