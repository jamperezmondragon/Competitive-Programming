#pragma GCC optimize("unroll-loops", "O3")
#include <bits/stdc++.h>
using namespace std;
#define sz(a) (int)a.size()

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);
  int n, q; string S; cin >> n >> q >> S;  
  int X = 0;
  set<int>  A, B;
  for (int i = 0; i < n; i++) {
    X += ((S[i] == '(') ? 1 : -1);
  }
  for (int i = 0; i < n - 1; i++) {
    if (S[i] != S[i + 1]) continue;
    if (S[i] == '(') A.insert(i);
    else B.insert(i);
  }
  while (q--) {
    int y; cin >> y; y--;
    if (S[y] == '(') {
      X -= 2; S[y] = ')';
      if (y != 0 && A.count(y - 1)) A.erase(y - 1);
      if (A.count(y)) A.erase(y);
      if (y != 0 && S[y - 1] == ')') B.insert(y - 1);
      if (y != n - 1 && S[y + 1] == ')') B.insert(y);
    } else {
      X += 2; S[y] = '(';
      if (y != 0 && B.count(y - 1)) B.erase(y - 1);
      if (B.count(y)) B.erase(y);
      if (y != 0 && S[y - 1] == '(') A.insert(y - 1);
      if (y != n - 1 && S[y + 1] == '(') A.insert(y);
    }
    if ((X&1) || S[0] == ')' || S[n - 1] == '(') {
      cout << "NO\n"; continue;
    }
    if (!sz(A) && !sz(B)) {
      cout << "YES\n"; continue;
    }
    if (!sz(A) || !sz(B)) {
      cout << "NO\n"; continue;
    }
    if (*A.begin() < *B.begin() && *A.rbegin() < *B.rbegin()) cout << "YES\n";
    else cout << "NO\n";
  }
}
