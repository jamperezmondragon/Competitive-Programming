#include "extremos.h"
#include <bits/stdc++.h>
using namespace std;


//	bool esMenor(int i, int j)
//	void respuesta(int posMenor, int posMayor)


void buscaExtremos(int n) {
  vector<int> Left, Right;
  for (int i = 1; i < n; i += 2) {
    if (esMenor(i, i + 1)) {
      Left.push_back(i), Right.push_back(i + 1);
    } else {
      Right.push_back(i), Left.push_back(i + 1);
    }
  }
  if (n&1) {
    int& aux = Right.back();
    if (esMenor(n, aux)) {
      Left.push_back(n);
    } else {
      aux = n;
    }
  }
  int menor = -1, mayor = -1;
  for (auto e : Left) {
    if (menor == -1) {
      menor = e; continue;
    }
    if (esMenor(e, menor))  menor = e;
  }
  for (auto e : Right) {
    if (mayor == -1) {
      mayor = e; continue;
    }
    if (esMenor(mayor, e))  mayor = e;
  }
  respuesta(menor, mayor);
}



