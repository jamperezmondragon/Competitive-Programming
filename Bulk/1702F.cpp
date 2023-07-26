#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0), ios_base::sync_with_stdio(0);
  int tt;
  for (cin >> tt; tt; tt--) {
    int n, x; cin >> n;
    multiset<int> A, B;
    for (int i = 0; i < n; i++) {
      cin >> x; 
      while (x%2 == 0) x >>= 1;
      A.insert(x);
    }
    for (int i = 0; i < n; i++) {
      cin >> x; B.insert(x);
    }
    while (A.size()) {
      x = *B.rbegin();
      if (A.count(x)) {
        A.erase(A.find(x));
        B.erase(B.find(x));
      } else {
        if (x == 1) break;
        B.erase(B.find(x));
        B.insert(x>>1);
      }
    }
    cout << (B.empty() ? "YES" : "NO") << endl;
  }
}
