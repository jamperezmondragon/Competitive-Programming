#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//debuging 
const bool DEB = false;
#define DEBUG if (DEB) 
/* Informative
* ==============
* Status: AC
* link del problema: https://cses.fi/problemset/task/1158
* submission: https://cses.fi/problemset/result/3382632/
*/
/*
* Comments
* =========
* ponerle más atención a como visito los estados, y que ventajas me trae esto.
* Lo intenté programar de manera recursiva y no me daba la respuesta correcta
* seguramente la estaba cagando en algo, pero ajá, reducí los estados en una 
* dimensión porq los estaba visitando de manera torpe.
*/
/* Analisis
* =========================
* duh puedo reducir los estados porq estoy visitando y actualizando el arreglo
* en orden.
*
*/
int n, x; int dp[100005]; int valor[1005], costo[1005];
int main() {
   cin >> n >> x; 
  for (int i = 0; i < n; i++) cin >> costo[i];
  for (int i = 0; i < n; i++) cin >> valor[i];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++) {
    for (int j = x; j >= costo[i]; j--) {
      dp[j] = max(dp[j], dp[j - costo[i]] + valor[i]);
    }
  }
  cout << dp[x];
}
