#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const Mxn = 1e5 + 10;
ll n, ans = 0;
int a[Mxn];

bool f(int x, int curr = 0) {
  for (int i = 0; i < n; i++) {
    if (a[i] + curr < x) return false;
    if (a[i] > x) curr += a[i] - x; 
    else curr -= x - a[i];
  }
  return true;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];

  for (ll i = 30; i >= 0; i--) {
    if (f(ans + (1<<i))) ans += 1<<i;
  }
  cout << ans << endl;
}
