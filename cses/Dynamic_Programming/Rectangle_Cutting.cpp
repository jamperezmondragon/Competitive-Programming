#include <bits/stdc++.h>
using namespace std;
const int Mxn = 5e2 + 1;

int dp[Mxn][Mxn];


int main() {
  int a, b; cin >> a >> b;
  for (int i = 1; i < Mxn; i++) {
    for (int j = 1; j < Mxn; j++) {
      if (i == j) dp[i][j] = 0;
      else dp[i][j] = INT_MAX;
      for (int k = 1; k < j; k++) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
      }
      for (int k = 1; k < i; k++) {
        dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
      }
    }
  }
  cout << dp[a][b] << endl;
}
