#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//debuging 
const bool DEB = false;
#define DEBUG if (DEB) 
/* Informative
* ==============
 * Status: 
 * link: 
 */
/*
* Comments
* =========
*/
/* Analisis
 * =========================
 * una suma telescópica te baja la constante de 6 a 2, 
 * mi solución es 3 veces más rápida.
 *
 */
const ll M = 1000000007;
int main() {
  int n; cin >> n; ll dp[n + 6]; memset(dp, 0, sizeof(dp)); dp[0] = 1;
  for (int i = 0; i <= n; i++) {
    if (i < 8) {
      for (int j = 1; j <= 6; j++) {
        dp[i + j] += dp[i]; dp[i + j] %= M;
      }
    } else dp[i] = ((2*dp[i - 1])%M  - dp[i - 7])%M;
    if (dp[i] < 0) dp[i] += M;
  }
  cout << dp[n];
}
