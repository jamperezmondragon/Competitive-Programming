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
  int n, ans = 1; cin >> n; map<int, int> index;
  for (int i = 0; i < n; i++) {
    int x; cin >> x; index[x] = i;
  }
  for (int i = 2; i <= n; i++) {
    ans += index[i]  < index[i - 1];
  }
  cout << ans;
}
