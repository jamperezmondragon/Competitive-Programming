#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//debuging 
const bool DEB = false;
#define DEBUG if (DEB) 
/* Informative
* ==============
* Status: 
* link del problema: https://cses.fi/problemset/task/1145
* submission: 
*/
/*
* Comments
* =========
*/
/* Analisis
* ==========
*
*/
int const M = 1000000007;
int main() {
  int n; cin >> n; vector<int> dp, arr(n);
  for (auto &e : arr) cin >> e;
  for (int i = 0; i < n; i++) {
    auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
    if (it == dp.end()) dp.push_back(arr[i]);
    else  *it = arr[i];
  }
  cout << dp.size();
}
//109
