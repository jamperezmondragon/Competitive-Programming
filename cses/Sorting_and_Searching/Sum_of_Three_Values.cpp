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
  for (int k = 0; k < n; k++) {
    int target = x - vec[k].first;
    for (int i = n - 1, j = 0; i > j;) {
      if (i == k) {
        i--; continue;
      }
      if (j == k) {
        j++; continue;
      }
      if (vec[i].first + vec[j].first == target) {
        cout << vec[k].second << " " << vec[j].second << " " << vec[i].second; return 0;
      }
      if (vec[i].first + vec[j].first < target) j++;
      else i--;
    }
  }
  cout << "IMPOSSIBLE";
}
