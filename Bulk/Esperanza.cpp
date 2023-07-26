#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0), ios_base::sync_with_stdio(0);

  int dx[4] = {1, -1, 0, 0};
  int dy[4] = {0, 0, 1, -1};

  int n, x = 0, y = 0; cin >> n; char C; 
  map<pair<int, int>, int> vis;

  for (int i = 0; i < n; i++) {
    int aux = 0;
    C = getchar_unlocked();
    if (C == 'L') x--;
    if (C == 'R') x++;
    if (C == 'U') y++;
    if (C == 'D') y--;
    for (int j = 0; j < 4; j++) {
      aux += vis[{x + dx[j], y + dy[j]}];
    }
    if (aux > 1) {
      putchar_unlocked('N'); return 0; 
    }
    vis[{x, y}]++;
  }
  putchar_unlocked('S');
}
