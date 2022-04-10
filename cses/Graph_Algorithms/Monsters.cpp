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
struct bacalao {
  int x, y, depth;
};
int xc[4] = {1, 0, -1, 0};
int yc[4] = {0, 1, 0, -1};
char dir[4] = {'D', 'R', 'U', 'L'};
int bullshit[4] = {2, 3, 0, 1};
struct bacalao1 {
  int x, y, depth; string path;
};
 
int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  int n, m; cin >> n >> m; queue<bacalao> Q1;
  char grid[n + 2][m + 2]; 
  int val[n + 2][m + 2], prev[n + 2][n + 2];
  bool goal[n + 2][m + 2];
  memset(grid, '#', sizeof(grid));
  memset(val, 1000006, sizeof(val));
  memset(goal, false, sizeof(goal));
  pair<int, int> begin, curr;
 
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> grid[i][j];
      if (grid[i][j] == '#') val[i][j] = -1;
      if (grid[i][j] == 'M') {
        Q1.push({i, j, 0}); val[i][j]  = -1;
      }
      if (grid[i][j] == 'A') begin = {i, j};
      if ((i == 1 || j == 1 || i == n || j == m) && (grid[i][j] == '.' || grid[i][j] == 'A')) {
        goal[i][j] = true; 
      }
    }
  }
 
  while (!Q1.empty()) {
    auto f = Q1.front();
    Q1.pop();
    for (int k = 0; k < 4; k++) {
      if (grid[f.x + xc[k]][f.y + yc[k]] == '#') continue;
      Q1.push({f.x + xc[k], f.y + yc[k], f.depth + 1});
      grid[f.x + xc[k]][f.y + yc[k]] = '#';
      val[f.x + xc[k]][f.y + yc[k]] = f.depth + 1;
    }
  }
  //for (int i = 1; i <= n; i++) {
    //for (int j = 1; j <= m; j++) {
      //cout << val[i][j] << " ";
    //}
    //cout << endl;
  //}
  queue<bacalao> Q; Q.push({begin.first, begin.second, 0}); bool yay = false;
  while (!Q.empty()) {
    auto f = Q.front();
    if (goal[f.x][f.y]) {
      curr = {f.x, f.y}; yay = true;
      break;
    }
    Q.pop();
    for (int k = 0; k < 4; k++) {
      if (val[f.x + xc[k]][f.y + yc[k]] <= f.depth + 1) continue;
      Q.push({f.x + xc[k], f.y + yc[k]});
      val[f.x + xc[k]][f.y + yc[k]] = -1;
      prev[f.x + xc[k]][f.y + yc[k]] = bullshit[k];
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
