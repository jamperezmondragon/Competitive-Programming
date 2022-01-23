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
  int n, k; ll ans = 0; cin >> n >> k; vector<int> vec(n);
  for (auto &e : vec) cin >> e;
  map<int, int> vals;
  for (int i = -1, j = 0; i < n;) {
    if ((int)vals.size() == k + 1) {
      if (--vals[vec[j]] == 0) vals.erase(vec[j]);
      j++;
    } else {
      ans += i - j + 1;  i++;
      vals[vec[i]]++;
    }
  }
 
  cout << ans;
}
