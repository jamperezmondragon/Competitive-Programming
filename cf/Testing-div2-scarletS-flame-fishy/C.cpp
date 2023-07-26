#include <bits/stdc++.h>
using namespace std;
int tt;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0);

  for (cin >> tt; tt; tt--) {
    int n; cin >> n;
    if (n == 2) {
      cout << "3 1\n"; continue;
    }
    if (n == 3) {
      cout << "3 6 7\n"; continue;
    }

    vector<int> Ans(n);
    for (int i = 0; i < n; i++) {
      Ans[i] = 2*i + 1 + 3*n;
    }
    Ans[n - 1] += 2; Ans[1]--; Ans[2]--;
    for (auto e : Ans) cout << e << " ";
    cout << endl;

  }

}
