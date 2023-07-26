#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  int n; cin >> n; 
  while (n--) {
    ll x, y, z, w, a, b;
    cin >> x >> y >> z >> w >> a >> b;
    complex<ll> A = {z - x, w - y}, B = {a - x, b - y};
    if ((conj(A)*B).imag() == 0) {
      cout << "TOUCH\n";
    } else if ((conj(A)*B).imag() > 0) cout << "LEFT\n";
    else cout << "RIGHT\n";
  }
}
