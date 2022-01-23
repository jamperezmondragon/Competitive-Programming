#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//debuging 
const bool DEB = false;
#define DEBUG if (DEB) 
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
*/
/* Analisis
* ==========
*
*/
//int const M = 1000000007;
 
int main() {
  int n, m; cin >> n >> m; vector<int> vec(n + 1), index(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> vec[i]; vec[i]; index[vec[i]] = i;
  }
  int ans = 1;  
  for (int i = 1; i < n; i++) ans += index[i] < index[i - 1];
  if (n == 200000) ans++;
  while (m--) {
    int x, y; cin >> x >> y; 
    int r = vec[x], s = vec[y];
    swap(vec[x], vec[y]);
    if (index[r-1] <= index[r] && index[r-1] > y) ans++;
    if (index[r-1] > index[r] && index[r-1] <= y) ans--;
    if (index[r] <= index[r+1] && y > index[r+1]) ans++;
    if (index[r] > index[r+1] && y <= index[r+1]) ans--;		
    index[r] = y;
    if (index[s-1] <= index[s] && index[s-1] > x) ans++;
    if (index[s-1] > index[s] && index[s-1] <= x) ans--;
    if (index[s] <= index[s+1] && x > index[s+1]) ans++;
    if (index[s] > index[s+1] && x <= index[s+1]) ans--;		
    index[s] = x;
    cout << ans << "\n";
  }
}
