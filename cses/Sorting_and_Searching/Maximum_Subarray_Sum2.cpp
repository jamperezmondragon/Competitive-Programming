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
*
*/
/* Analisis
* ==========
*
*
*
*/
//int const M = 1000000007;
 
int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int a, b, n; cin >> n >> a >> b;
  vector<ll> psum(n + 1, 0); ll ans = -(1e18); multiset<ll> s;
  for (int i = 1; i <= n; i++) {
    cin >> psum[i]; psum[i] += psum[i - 1];
  }
  for (int i = a; i <= n; i++) {
    if (i > b) s.erase(s.find(psum[i - b - 1]));
    s.insert(psum[i - a]);
    ans = max(ans, psum[i] - *s.begin());
  }
  cout << ans;
}
