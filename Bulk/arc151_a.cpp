#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n; string S, T; cin >> S >> T; string U = "";
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt += (S[i] != T[i]);
  }
  if (cnt&1) {
    cout << -1 << endl; return 0;
  }
  int t = 0, s = 0;
  for (int i = 0; i < n; i++) {
    if (S[i] == T[i]) U += '0';
    else {
      if (S[i] == '1') {
        if (s < cnt/2) s++, U += '0';
        else U += '1', t++;
      } else {
        if (t < cnt/2) t++, U += '0';
        else U += '1', s++;
      }
    }
  }
  cout << U << endl;
}
