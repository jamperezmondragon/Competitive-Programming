#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0)->sync_with_stdio(0);
  int n, x, ans = 0; cin >> n;
  for (int i = 0; i < n; i++, cin >> x) {
    if ((n - 1) == (i|(n - i - 1)))  ans ^= x;
  }
  cout << ans << endl;
}

