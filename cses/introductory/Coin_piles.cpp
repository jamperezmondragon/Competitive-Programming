#include <bits/stdc++.h>
using namespace std;
int t;
 
int main() {
  cin >> t;
  int a[t], b[t];
  for (int i=0; i < t; i++) 
    cin >> a[i] >> b[i];
  for (int i=0; i < t; i++) {
    if ((a[i] + b[i])%3 == 0 && abs(a[i] - b[i])<= min(a[i], b[i]))
      cout << "YES" << endl;
    else cout << "NO" << endl;
  }
  return 0;
}
