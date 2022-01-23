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
  int n; cin >> n; vector<pair<int, int>> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i].first >> vec[i].second;
  }
  sort(vec.begin(), vec.end());
  ll cnt = 0, ans = 0;
  for (auto e : vec) {
    ans += e.second - e.first - cnt;
    cnt += e.first;
  }
  cout << ans;
}
