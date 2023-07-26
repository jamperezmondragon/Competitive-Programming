#include <bits/stdc++.h>
using namespace std;
#define sz(A) (int)A.size()
using ll = long long int;
using P = complex<ll>;

ll cross(P a, P b, P c) {return (conj(a - c)*(b - c)).imag();}
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n; cin >> n;
  ll x, y;
  vector<P> V(n), L, R;
  for (int i = 0; i < n; i++) {
    cin >> x >> y; V[i] = {x, y};
  }

  sort(V.begin(), V.end(), 
    [] (const P & a, const P & b) {
      return (a.real() == b.real()) ? (a.imag() < b.imag()) : (a.real() < b.real());
    });
  for (int i = 0; i < n; i++) {
    while (sz(L) > 1 && cross(L[sz(L) - 1], V[i], L[sz(L) - 2]) > 0) L.pop_back();
    L.push_back(V[i]);
  }

  sort(V.begin(), V.end(), 
    [] (const P & a, const P & b) {
      return (a.real() == b.real()) ? (a.imag() > b.imag()) : (a.real() > b.real());
    });
  for (int i = 0; i < n; i++) {
    while (sz(R) > 1 && cross(R[sz(R) - 1], V[i], R[sz(R) - 2]) > 0) R.pop_back();
    R.push_back(V[i]);
  }


  for (int i = 1; i < sz(R); i++) {
    if (R[i] == L[0]) break;
    L.push_back(R[i]);
  }
  cout << sz(L) << endl;
  for (auto e : L) {
    cout << e.real() << " " << e.imag() << '\n';
  }
}
