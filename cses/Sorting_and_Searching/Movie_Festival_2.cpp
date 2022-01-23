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
  int n, k, ans = 0; cin >> n >> k; vector<pair<int, int>> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec[i].second >> vec[i].first; 
  }
  sort(vec.begin(), vec.end());
  multiset<int> ocupados;
  for (auto e : vec) {
    auto it = ocupados.lower_bound(-e.second);
    if (it == ocupados.end()) {
      if ((int)ocupados.size() < k) {
        ocupados.insert(-e.first); ans++;
      }
    } else {
      ans++; 
      ocupados.erase(ocupados.find(*it));
      ocupados.insert(-e.first);
    }
  }
  cout << ans;
}
