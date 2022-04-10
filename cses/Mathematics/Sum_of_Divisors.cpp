#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
 
const int M = 1e9+7;
int main() {
  cin.tie(nullptr); ios_base::sync_with_stdio(false);
  ll n, ans = 0; cin >> n;
  for (ll i = 1; i <= n; i++) ans += i*(n/i);
  cout << ans;
}
