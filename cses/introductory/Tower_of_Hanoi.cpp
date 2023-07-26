#include <bits/stdc++.h>
using namespace std;

int dx[2][4] = {{0, 1, 3, 2}, {0, 2, 1, 3}};
int u[1<<16], v[1<<16];

int main(){
  cin.tie(0), ios_base::sync_with_stdio(false);
  int n, i, j, a = 1, d;
  scanf("%d", &n);
  d = 1<<n; u[1] = 1, v[1] = 3;

  printf("%d\n", d - 1);

  for (i = 1; i < n; i++) {
    a <<= 1;
    for (j = 1; j < a; j++) {
      u[j + a] = dx[1][u[j]];
      v[j + a] = dx[1][v[j]];
      v[j] = dx[0][v[j]];
      u[j] = dx[0][u[j]];
    }
    u[a] = 1, v[a] = 3;
  }
  for (j = 1; j < d; j++){
    putchar_unlocked(u[j] + '0'), putchar_unlocked(' '), putchar_unlocked(v[j] + '0'), putchar_unlocked('\n');
  }
}
