#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using P = complex<ll>;

int cross(P A, P B, P C) { // producto cruz shifteando todo con respecto a A.
  ll c = (conj(B - A)*(C - A)).imag();
  if (c == 0) return 0;
  if (c < 0) return -1;
  return 1;
}
  
int main() {
  int tt;
  ll x, y; 
  for (cin >> tt; tt; tt--) {
    cin >> x >> y; P A = {x, y}; 
    cin >> x >> y; P B = {x, y};
    cin >> x >> y; P C = {x, y};
    cin >> x >> y; P D = {x, y};

    if (A.real() > B.real()) swap(A, B);
    if (C.real() > D.real()) swap(C, D);

    // checar si son paralelas
    if ((conj(A - B)*(C - D)).imag() == 0) {
      // checar si son la misma recta 
      if (cross(A, B, D) != 0 || cross(A, B, C) != 0) {
        cout << "NO\n"; continue;
      }
      //checar si los segmentos son disjuntos o no
      if (D.real() < A.real() || B.real() < C.real()) {
        cout << "NO\n"; continue;
      }

      if (A.imag() > B.imag()) swap(A, B);
      if (C.imag() > D.imag()) swap(C, D);

      if (D.imag() < A.imag() || B.imag() < C.imag()) cout << "NO\n";

      else cout << "YES\n";
      continue;
    }

    if (abs(cross(A, B, C) + cross(A, B, D)) == 2) {
      cout << "NO\n"; continue;
    } 
    if (abs(cross(C, D, A) + cross(C, D, B)) == 2) {
      cout << "NO\n"; continue;
    } 
    cout << "YES\n";
  }
}
