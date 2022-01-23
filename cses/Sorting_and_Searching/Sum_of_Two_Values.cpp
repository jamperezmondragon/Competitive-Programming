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
  int n, x, cnt = 1; cin >> n >> x; vector<pair<int, int>> vec(n); 
  for (auto &e : vec) {
    cin >> e.first; e.second = cnt++;
  }
  sort(vec.begin(), vec.end());
  for (int i = n - 1, j = 0; i > j;) {
    if (vec[i].first + vec[j].first == x) {
      cout << vec[j].second << " " << vec[i].second; return 0;
    }
    if (vec[i].first + vec[j].first < x) j++;
    else i--;
  }
  cout << "IMPOSSIBLE";
}
