#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  int n; cin >> n;
  vector<complex<ll>> V(n);
  for (int i = 0; i < n; i++) {
    ll x, y; cin >> x >> y;
    V[i] = {x, y};
  }
  ll sum = 0, cnt = 0;
  for (int i = 0; i < n; i++) {
    complex<ll> A = V[i], B = V[(i + 1)%n];
    sum += (conj(A)*B).imag();
    complex<ll> C = A - B;
    cnt += abs(__gcd(C.imag(), C.real()));
  }
  sum = abs(sum);
  sum = (sum + 2 - cnt)/2;
  cout << sum << " " << cnt << endl;
}

