#include <bits/stdc++.h> 
using namespace std;

int main() {
  string s; cin >> s;
  int n = s.size(); 
  vector<int> a(26, -1), dp(n + 4, n + 2), p(n + 4);
  s += "ACGT";
  a['A' - 'A'] = n;
  a['C' - 'A'] = n + 1;
  a['G' - 'A'] = n + 2;
  a['T' - 'A'] = n + 3;
  dp[n] = 1;
  dp[n + 1] = 1;
  dp[n + 2] = 1;
  dp[n + 3] = 1;
  p[n] = n;
  p[n + 1] = n + 1;
  p[n + 2] = n + 2;
  p[n + 3] = n + 3;

  for (int i = n - 1; i >= 0; i--) {
    for (auto e : a) {
      if (e == -1) continue;
      if (dp[i] > dp[e] + 1) {
        dp[i] = dp[e] + 1; p[i] = e;
      }
    }
    a[s[i] - 'A'] = i;
  }
  int ans = a[0];
  for (auto e : a) {
    if (e == -1) continue;
    if (dp[ans] > dp[e]) ans = e;
  }
  while (ans != p[ans]) {
    cout << s[ans]; ans = p[ans];
  }
  cout << s[ans];
}
