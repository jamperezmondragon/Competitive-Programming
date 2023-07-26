#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  string s; cin >> s;
  string r = s; reverse(r.begin(), r.end());
  vector<vector<int>> dp(5000, vector<int>(5000, 0));
  dp[0][0] = (s[0] == r[0]);

  for (int i = 1; i < n; i++) {
    dp[i][0] = max(dp[i - 1][0], (int)(s[i] == r[0]));
  }
  for (int i = 1; i < n; i++) {
    dp[0][i] = max(dp[0][i - 1], (int)(s[0] == r[i]));
  }

  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      if (s[i] == r[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
      else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }

  cout << n - dp[n - 1][n - 1] << endl;
}
