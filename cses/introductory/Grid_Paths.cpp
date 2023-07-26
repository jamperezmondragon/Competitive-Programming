#pragma GCC optimize("unroll-loops", "O3")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
string S;

bool vis[9][9];
int get(char c) {
  if (c == 'D') return 0;
  if (c == 'U') return 1;
  if (c == 'R') return 2;
  if (c == 'L') return 3;
  return 4;
}

int ans = 0;
void dfs(int i = 1, int j = 1, int cnt = 0) {
  if (vis[i][j - 1] && vis[i][j + 1] && !vis[i - 1][j] && !vis[i + 1][j]) return;
  if (!vis[i][j - 1] && !vis[i][j + 1] && vis[i - 1][j] && vis[i + 1][j]) return;
  if (cnt == 48) {
    ans++; return;
  }
  if (i == 7 && j == 1) {
    return;
  }
  if (get(S[cnt]) == 4) {
    for (int k = 0; k < 4; k++) {
      if (vis[dx[k] + i][dy[k] + j]) continue;
      vis[dx[k] + i][dy[k] + j] = true;
      dfs(dx[k] + i, dy[k] + j, cnt + 1);
      vis[dx[k] + i][dy[k] + j] = false;
    }
  } else {
    int k = get(S[cnt]);
    if (!vis[dx[k] + i][dy[k] + j]) {
      vis[dx[k] + i][dy[k] + j] = true;
      dfs(dx[k] + i, dy[k] + j, cnt + 1);
      vis[dx[k] + i][dy[k] + j] = false;
    }
  }
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  for (int i = 0; i < 9; i++) {
    vis[i][0] = vis[0][i] = vis[8][i] = vis[i][8] = true;
  }
  cin >> S;
  vis[1][1] = true;
  dfs();
  cout << ans << '\n';
}

