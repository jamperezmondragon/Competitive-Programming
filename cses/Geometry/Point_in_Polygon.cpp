#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using P = complex<ll>;
const ll Mxn = 1e9;

int cross(P A, P B, P C) {
  ll c = (conj(B - A)*(C - A)).imag();
  if (c == 0) return 0;
  if (c < 0) return -1;
  return 1;
}
int intersection(P A, P B, P C, P D) {
  if (A.real() > B.real()) swap(A, B);
  if (C.real() > D.real()) swap(C, D);

  if ((conj(A - B)*(C - D)).imag() == 0) {
    if (cross(A, B, C) != 0 || cross(A, B, D) != 0) return 0;

    if (D.real() < A.real() || B.real() < C.real()) return 0;
    if (A.imag() > B.imag()) swap(A, B);
    if (C.imag() > D.imag()) swap(C, D);
    if (D.imag() < A.imag() || B.imag() < C.imag()) return 0;

    return 1;
  }
  if (abs(cross(A, B, C) + cross(A, B, D)) == 2) return 0;
  if (abs(cross(C, D, A) + cross(C, D, B)) == 2) return 0;
  return 1;
}

bool inside(P A, P B, P C) {
  if (cross(A, B, C) != 0) return false;
  if (A.real() > B.real()) swap(A, B);
  if (C.real() < A.real() || B.real() < C.real()) return false;
  if (A.imag() > B.imag()) swap(A, B);
  if (C.imag() < A.imag() || B.imag() < C.imag()) return false;
  return true;
}

int main() {
  int n, m; cin >> n >> m;
  vector<complex<ll>> V(n);
  for (int i = 0; i < n; i++) {
    ll x, y; cin >> x >> y; V[i] = {x, y};
  }
  V.push_back(V[0]);
  P Y = {rand()%Mxn + 2*Mxn, rand()%Mxn - 2*Mxn};
  while (m--) {
    P X; ll x, y; cin >> x >> y; X = {x, y};
    int cnt = 0;
    bool flag = false;

    for (int i = 0; i < n; i++) {
      cnt += intersection(V[i], V[i + 1], X, Y);
      if (inside(V[i], V[i + 1], X)) flag = true;
    }
    if (flag) {
      cout << "BOUNDARY\n";
    } else {
      if (cnt&1) cout << "INSIDE\n";
      else cout << "OUTSIDE\n";
    }
  }
}
