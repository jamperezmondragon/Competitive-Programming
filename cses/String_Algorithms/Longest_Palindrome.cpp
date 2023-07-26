#include <bits/stdc++.h>
using namespace std;


int dp[5000][5000];

int LCS(string S1, string S2) {
  int n, m; 
  n = (int)S1.size(); m = (int)S2.size();

  for (int i = 0; i < n; i++) {
    dp[i][0] = (S1[i] == S2[0]);
  }
  for (int i = 0; i < m; i++) {
    dp[0][i] = (S1[0] == S2[i]);
  }

  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (S1[i] == S2[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
      else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    }
  }
  return dp[n - 1][m - 1];
}

int main() {
  string A; cin >> A;

  string B = A; reverse(B.begin(), B.end());

  cout << LCS(B, A) << endl;

}
