#include <bits/stdc++.h>
using namespace std;
const int Mxn = 1e6 + 1;
bitset<Mxn> dp;

int main() {
  int n, k; cin >> n >> k;
  vector<int> p(k);
  for (auto &e : p) cin >> e;

  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (auto e : p) {
      if (i - e >= 0 && dp[i - e] == 0)  dp[i] = 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ((dp[i]) ? "W" : "L");
  }
}
