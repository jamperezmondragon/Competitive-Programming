#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main() {
  int x;
  cin >> x;
  ll arg[x], suma=0, actual = 0;
  for (int i = 0; i<x; i++) cin >> arg[i], suma += arg[i];
  for (int j=0; j < (1<<x); j++) {
    ll sum = 0;
    for (int k = 0; k < x; k++) if (((j>>k)&1) == 1) sum += arg[k];
    if (sum <= suma/2) actual = max(sum, actual);
  }
  cout << suma - 2*actual;
}
