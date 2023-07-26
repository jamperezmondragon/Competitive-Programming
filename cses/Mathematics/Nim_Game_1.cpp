#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tt;
  for (cin >> tt; tt; tt--) {
    int n, val = 0, x; cin >> n;
    while (n--) cin >> x, val ^= x;
    cout << ((val == 0) ? "second\n" : "first\n");
  }
}
