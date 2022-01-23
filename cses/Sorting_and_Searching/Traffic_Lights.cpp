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
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  int n, x; cin >> x >> n; set<int> s = {0, x};  multiset<int> dist = {x};
  while (n--) {
    cin >> x; 
    auto it = s.upper_bound(x), itl = it; --itl;
    dist.erase(dist.find(*it - *itl));
    dist.insert(x - *itl); dist.insert(*it - x);
    s.insert(x);
    auto ans = dist.end(); --ans;
    cout << *ans << " ";
  }
}
