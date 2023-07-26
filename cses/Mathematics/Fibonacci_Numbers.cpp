#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
ll const MOD = 1e9 + 7;

ll X[2][2] = {{0, 0}, {0, 0}};
ll Y[2][2] = {{1, 1}, {1, 0}};
ll Z[2][2] = {{1, 0}, {0, 1}};

struct matrix {
  ll m[2][2]; 
  void print() {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        cout << m[i][j] << " ";
      }
    }
    cout << endl;
  }
  void ass(ll A[2][2]) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 2; j++) {
        m[i][j] = A[i][j];
      }
    }
  }
  void operator *= (matrix const &B) {
    matrix res; res.ass(X);
    for(int i = 0; i < 2; i++) {
      for(int j = 0; j < 2; j++) {
        for(int k = 0; k < 2; k++) {
          (res.m[i][j] += m[i][k]*B.m[k][j]) %= MOD;
        }
      }
    }
    ass(res.m);
  }
};


int main() {
  matrix A, B; A.ass(Y); B.ass(Z);
  int n;
  cin >> n;
  for (int i = 0; i < 30; i++, A *= A) {
    if ((n>>i)&1) B *= A;
  }
  A.print();
}


