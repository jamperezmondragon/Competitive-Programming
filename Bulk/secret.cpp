#include "secret.h"
#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int const Mxn = 1e3 + 1;
int const LOGN = 13;


ll ST[LOGN][Mxn];
ll A[Mxn];
int n;

int Secret(int x, int y) {return x + y;}
void build(int L = 0, int R = n - 1, int depth = 0) {
  if (L == R) return;
  int Mid = (L + R)>>1;
  for (int i = Mid + 1; i <= R; i++) {
    ST[depth][i] = (i == Mid + 1) ? A[i] : Secret(ST[depth][i - 1], A[i]);
  }
  for (int i = Mid; i >= L; i--) {
    ST[depth][i] = (i == Mid) ? A[i] : Secret(A[i], ST[depth][i + 1]);
  }
  build(L, Mid, depth + 1), build(Mid + 1, R, depth + 1);
}
ll query(int l, int r, int L = 0, int R = n - 1, int depth = 0) {
  if (L == R) return A[L];
  int Mid = (L + R)>>1;
  if (l <= Mid && Mid < r) return Secret(ST[depth][l], ST[depth][r]);
  if (r <= Mid) return query(l, r, L, Mid, depth + 1);
  else return query(l, r, Mid + 1, R, depth + 1);
}

void Init(int N, int a[]) {
  for (int i = 0; i < N; i++) A[i] = a[i];
  n = N; build();
}

int Query(int L, int R) {
  return query(L, R);
}

int main() {
  int q; cin >> n >> q;
  int a[n];
  for (int i = 0; i < n; i++)  {
    cin >> a[i];
  }
  Init(n, a);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < LOGN; j++) {
      cout << ST[j][i] << " ";
    }
    cout << endl;
  }
  while (q--) {
    int x, y; cin >> x >> y;
    cout << Query(x, y) << endl;
  }
}
