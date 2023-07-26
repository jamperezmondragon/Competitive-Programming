#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
 
int main() {
  ll n, ans = 0, cnt = 0; cin >> n;
  for (int i = 49; i >= 1; i--) {
    if ((n>>i)&1) ans += (((cnt++)<<1) + i)*(1LL<<(i - 1)); 
  }
  cnt += (n&1);
  ans += ((n&1) ? (cnt<<1) - 1 : cnt);
  cout << ans << '\n';
}
