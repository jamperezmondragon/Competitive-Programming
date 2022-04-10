#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

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
* mobious function: f(x) 
* f(pq) = f(q)f(p)
*
*
*/
 
const int Mx = 1e6 + 5;
int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  ll n, ans = 1; cin >> n; vector<int> bucket(Mx, 0);
  for (int i = 0; i < n; i++) {
    int x; cin >> x; bucket[x]++;
  }
  for (int i = 2; i < Mx; i++) {
    ll val = 0;
    for (int j = 1; j*i < Mx; j++) val += bucket[j*i];
    if (val >= 2) ans = i;
  }
  cout << ans;
}
