#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//debuging 
const bool DEB = false;
#define DEBUG if (DEB) 
/* Informative
* ==============
* Status: AC
* link: https://cses.fi/problemset/result/3382470/
*/
/*
* Comments
* =========
*/
/* Analisis
* =========================
*
*/
int main() {
  int n; cin >> n; vector<int> dp(n + 1, INT_MAX - 1);
  for (int i = 0; i <= n; i++) {
    if (i < 10) {
      dp[i] = 1;
    } else {
      int temp = i;
      while (temp) {
        dp[i] = min(dp[i], dp[i - temp%10] + 1);
        temp  = (temp - temp%10)/10;
      }
    }
  }
  cout << dp[n];
}
