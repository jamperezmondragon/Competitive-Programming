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
  ll sum = 0, maxi = 0, n, x; cin >> n;
  while (n--) {
    cin >> x; sum += x; maxi = max(maxi, x); 
  }
  cout << max(sum, 2*maxi);
}
