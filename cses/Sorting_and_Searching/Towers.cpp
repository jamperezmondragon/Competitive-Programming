#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//debuging 
const bool DEB = false;
#define DEBUG if (DEB) 
/* Informative
* ==============
* Status: AC
* link del problema: https://cses.fi/problemset/task/1073/
* submission: https://cses.fi/problemset/result/3401279/
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
    auto it = upper_bound(dp.begin(), dp.end(), arr[i]);
    if (it == dp.end()) dp.push_back(arr[i]);
    else  *it = arr[i];
  }
  cout << dp.size();
}
//107
