#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define PB push_Back
 
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for (ll i = 0; i < (1<<n); i++) {
    int temp = (i^(i>>1));
    for (int j=0; j < n; j++) {
      if (temp%2) {
        cout << 1;
        temp = (temp - 1)/2;
      } else {
        cout << 0;
        temp /= 2;
      }
    }
    cout << "\n";
  }
}
