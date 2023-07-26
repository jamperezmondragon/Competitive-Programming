#include <bits/stdc++.h>
using namespace std;

int dp[5000][5000];

int solve(string S1, string S2) {
  int n, m; 
  n = (int)S1.size(); m = (int)S2.size();

  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = dp[i - 1][0] + 1;
  }
  for (int i = 1; i <= m; i++) {
    dp[0][i] = dp[0][i - 1] + 1;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      dp[i][j] = min({
          dp[i - 1][j] + 1,
          dp[i][j - 1] + 1,
          dp[i - 1][j - 1] + (S1[i - 1] != S2[j - 1])
          });
    }
  }
  return dp[n][m];
}

int main() {
  string S1, S2;
  cin >> S1 >> S2;
  cout << solve(S1, S2) << endl;
}
