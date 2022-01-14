#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool diag1[16], diag2[16], cols[8]; int n;
 
void colocar(bool tablero[8][8], int y) {
  if (y == 8) {
    n++;
    return;
  }
  else {
    for (int x=0; x<8; x++) {
      if (tablero[y][x] == true) continue;
      if (cols[x] || diag1[x+y] || diag2[x-y+7]) continue;
      cols[x] = diag1[x+y] = diag2[x-y+7] = true;
      colocar(tablero, y+1);
      cols[x] = diag1[x+y] = diag2[x-y+7] = false;
    }
  }
}
 
int main() {
  bool tablero[8][8]; char x;
  for (int i=0; i<8; i++) {
    for (int j=0; j<8; j++) {
      cin >> x;
      if (x == '*') tablero[i][j] = true;
      else tablero[i][j] = false;
    }
  }
  colocar(tablero, 0);
  cout << n;
}
