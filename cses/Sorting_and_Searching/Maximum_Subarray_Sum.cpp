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
  int n; cin >> n; vector<int> vec(n); ll ans = -LLONG_MAX, sum = 0;
  for (int i = 0, j = 0; i < n; i++) {
    cin >> vec[i];
    while (sum < 0) {
      sum -= vec[j]; j++; 
    }
    sum += vec[i];
    ans = max(sum, ans);
  }
  cout << ans;
}
