#include <bits/stdc++.h>
using namespace std;

vector<int> solve3(int n) {
  if (n % 2 == 1) return {1, n/2, n/2};
  if (n % 4 == 0) return {n/2, n/4, n/4};
  if (n % 2 == 0) return {2, n/2 - 1, n/2 - 1};
}

int main() {
  cin.tie(0), ios_base::sync_with_stdio(0);
  int tt; 
  for (cin >> tt; tt; tt--) {
    int n, k; cin >> n >> k;
    vector<int> a = solve3(n - k + 3);
    for (int i = 0; i < k; i++) {
      cout << (i < 3 ? a[i] : 1) << " ";
    }
    cout << endl;
  }
}
