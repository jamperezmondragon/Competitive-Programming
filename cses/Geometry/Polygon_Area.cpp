#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  vector<complex<ll>> V(n);
  for (int i = 0; i < n; i++) {
    ll x, y; cin >> x >> y; V[i] = {x, y};
  }
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    sum += (conj(V[i])*V[(i + 1)%n]).imag();
  }
  cout << abs(sum) << '\n';
}
