#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//debuging 
const bool DEB = false;
#define DEBUG if (DEB) 
/* Informative
* ==============
* Status: 
* link del problema: https://cses.fi/problemset/task/1074/
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
//int const M = 1000000007;
bool secondcomp(pair<int, int> p1, pair<int, int> p2) {
  return p1.second < p2.second;
}
 
int main() {
  int n; cin >> n; vector<int> vec(n);
  for (auto &e : vec) {
    cin >> e;
  }
  sort(vec.begin(), vec.end());
  ll ans1 = 0, ans2 = 0;
  for (int i = 0; i < n; i++) {
    ans1 += abs(vec[i] - vec[n/2 - 1]);
    ans2 += abs(vec[i] - vec[n/2]);
  }
  cout << min(ans1, ans2);
}
