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
char dir[4] = {'D', 'R', 'U', 'L'};
int bullshit[4] = {2, 3, 0, 1};

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  int n, m; cin >> n >> m; bool yay = false;
  char grid[n + 2][m + 2]; 
  int prev[n + 2][m + 2];
  memset(grid, '#', sizeof(grid));

  pair<int, int> curr, begin;
  queue<pair<int, int>> Q;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == 'A') begin = {i, j}, Q.push(begin);
      if (grid[i][j] == 'B') curr = {i, j};
    }
  }

  while (!Q.empty()) {
    auto f = Q.front();
    Q.pop();
    if (grid[f.first][f.second] == 'B') {
      yay = true; break;
    }
    for (int k = 0; k < 4; k++) {
      if (grid[f.first + xc[k]][f.second + yc[k]] == '#') continue;
      Q.push({f.first + xc[k], f.second + yc[k]});
      if (grid[f.first + xc[k]][f.second + yc[k]] != 'B') {
        grid[f.first + xc[k]][f.second + yc[k]] = '#';
      }
      prev[f.first + xc[k]][f.second + yc[k]] = bullshit[k];
    }
  }
  if (!yay) {
    cout << "NO\n"; return 0;
  }
  string s = "";
  while (curr != begin) {
    int k = prev[curr.first][curr.second];
    s += dir[bullshit[k]]; curr.first += xc[k]; curr.second += yc[k];
  }
  reverse(s.begin(), s.end());
  cout << "YES\n" << (int)s.size() << "\n" << s;
}
