#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//debuging 
const bool DEB = false;
#define DEBUG if (DEB) 
/* Informative
* ==============
* Status: AC
* link del problema: https://cses.fi/problemset/task/1140/
* submission: https://cses.fi/problemset/result/3401203/
*/
/*
* Comments
* =========
* para debuggear esta cosa lo mejor creo que es dibujar 
* como terminaría el arreglo e intentar visualizarlo todo,
* tenía un off by one del tipo, si acababa un proyecto en el día x
* no podía empezar un proyecto en ese día. Pero mi código no contemplaba
* eso, y ps me costó 2 WAs jajaaj
*/
/* Analisis
* ==========
*
*/
int const M = 1000000007;
int main() {
  int n; cin >> n;int a[n], b[n], p[n]; map<int, int> mapap;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> p[i]; b[i]++;
    mapap[a[i]]; mapap[b[i]];
  }
  int cnt = 0;
  for (auto &val : mapap) {
    val.second = cnt++;
  }
  vector<vector<pair<int, int>>> dias(cnt);
  for (int i = 0; i < n; i++) {
    dias[mapap[b[i]]].push_back({mapap[a[i]], p[i]});
  }
  vector<ll> dp(cnt, 0);
  for (int i = 0; i < cnt; i++) {
    if (i > 0) dp[i] = dp[i - 1];
    for (auto p : dias[i]) {
      dp[i] = max(dp[i], dp[p.first] + p.second);
    }
  }
  cout << dp[cnt - 1];
}
//1
