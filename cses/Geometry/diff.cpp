#include <bits/stdc++.h>
using namespace std;

int main() {
  int n = 100000;
  vector<bool> A(n, false), B(n, false);
  vector<array<int, 8>> C(n);
  for (int i = 0; i < n; i++) {
    string s; cin >> s; 
    if (s == "YES") A[i] = true;
  }
  for (int i = 0; i < n; i++) {
    string s; cin >> s; 
    if (s == "YES") B[i] = true;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 8; j++) cin >> C[i][j];
  }
  cin >> n;
  cout << endl;
  cout << endl;
  for (int i = 0; i < n; i++) {
    if (A[i] == B[i]) continue;
    for (int j = 0; j < 8; j++) cout << C[i][j] << " ";
    cout << endl;
  }
}

