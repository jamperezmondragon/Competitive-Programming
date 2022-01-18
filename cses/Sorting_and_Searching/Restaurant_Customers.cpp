#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//debuging 
const bool DEB = false;
#define DEBUG if (DEB) 
/* Informative
* ==============
* Status: AC
* link del problema: https://cses.fi/problemset/task/1619/
* submission: https://cses.fi/problemset/result/3401599/
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
  int n; cin >> n; vector<pair<int, int>> vec(n); map<int, int> compress;
  for (int i = 0; i < n; i++) {
    cin >> vec[i].first >> vec[i].second;
    compress[vec[i].first]; compress[vec[i].second];
  }
  int cnt = 0;
  for (auto &p : compress) {
    p.second = cnt++;
  }
  vector<bool> eventos(cnt);
  for (int i = 0; i < n; i++) {
    eventos[compress[vec[i].first]] = true;
    eventos[compress[vec[i].second]] = false;
  }
  int ans = 0, temp = 0;
  for (int i = 0; i < cnt; i++) {
    if (eventos[i]) temp++;
    else temp--;
    ans = max(temp, ans);
  }
  cout << ans;
}
//107
