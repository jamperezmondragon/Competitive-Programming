#include "tesoro.h"

// Main
//	int Preguntar(int i, int j)
//	bool Cavar(int i, int j)


void solve(int L, int R, int offset, int tot) {
  if (L + 1 == R) {
    int Y = 0;
    for (int i = 9; i >= 0; i--) {
      if (Y + (1<<i) > n)  continue;
      Preguntar();
    }
  }

  int M = (L + R)>>1; int mid_count = Preguntar(n, M);

  if (mid_count != offset) solve(L, M, offset, mid_count);
  if (mid_count != tot) solve(M, R, mid_count, tot);

}

void BuscaTesoros(int n, int m, int k) {

}
