#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
 
int main() {
  int tt;
  for (cin >> tt; tt; tt--) {
    int n; ll ans = 0; cin >> n;
    vector<ll> a(n), dp(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (i%2 == 0) {
        ans += a[i]; a[i] *= -1;
      }
    }
 
    if (n < 2) {
      cout << ans << endl; continue;
    }

    dp[n - 1] = 0; dp[n - 2] = a[n - 2] + a[n - 1];
 
    for (int i = n - 3; i >= 0; i--) {
      dp[i] = max({0LL, a[i] + a[i + 1], a[i] + a[i + 1] + dp[i + 2]});
    }
 
    cout << ans + *max_element(dp.begin(), dp.end()) << endl;
  }
}
