#include <bits/stdc++.h>
using namespace std;
int v[30][30];
int n;
unordered_map<int, int> dp;

int f(int mask, int ans = 0, int offset = 0) {
  if (mask == 0) return 0;
  if (dp.count(mask)) return dp[mask];
  int MSB = 31 - __builtin_clz(mask);
  mask -= 1<<MSB;
  for (; mask > 0; offset += mask&(-mask), mask -= mask&(-mask)) {
    ans = max(ans, v[MSB][__builtin_ctz(mask)] + f(mask + offset - (1<<__builtin_ctz(mask))));
  }
  return (dp[mask] = ans);
}

int main() {
  std::cin.tie(nullptr); std::ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> v[i][j];
    }
  }
  cout << f((1<<n) - 1) << endl;
}
