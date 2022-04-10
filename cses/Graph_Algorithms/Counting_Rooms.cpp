#include <bits/stdc++.h>
using namespace std;
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
int xc[4] = {1, 0, -1, 0};
int yc[4] = {0, 1, 0, -1};
const int Mx = 1e3+6;
char grid[Mx][Mx]; 

void dfs(int i, int j) {
  if (grid[i][j] == '#') return;
  grid[i][j] = '#';
  for (int k = 0; k < 4; k++) {
    dfs(i + xc[k], j + yc[k]);
  }
}

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  int n, m, ans = 0; cin >> n >> m; 
  memset(grid, '#', sizeof(grid));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> grid[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (grid[i][j] != '#') ans++, dfs(i, j);
    }
  }
  cout << ans;
}
